/* Copyright (c) 2015-2016, The Linux Foundation. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are
* met:
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above
*       copyright notice, this list of conditions and the following
*       disclaimer in the documentation and/or other materials provided
*       with the distribution.
*     * Neither the name of The Linux Foundation nor the names of its
*       contributors may be used to endorse or promote products derived
*       from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
* ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
* BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
* IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

// System dependencies
#include <stdio.h>
#include <fcntl.h>
#include <media/msm_cam_sensor.h>

// Camera dependencies
#include "HAL3/QCamera3HWI.h"
#include "QCameraFlash.h"

extern "C" {
#include "mm_camera_dbg.h"
}

#define STRING_LENGTH_OF_64_BIT_NUMBER 21
volatile uint32_t gCamHal3LogLevel = 1;

namespace qcamera {

/*===========================================================================
 * FUNCTION   : getInstance
 *
 * DESCRIPTION: Get and create the QCameraFlash singleton.
 *
 * PARAMETERS : None
 *
 * RETURN     : None
 *==========================================================================*/
QCameraFlash& QCameraFlash::getInstance()
{
    static QCameraFlash flashInstance;
    return flashInstance;
}

/*===========================================================================
 * FUNCTION   : QCameraFlash
 *
 * DESCRIPTION: default constructor of QCameraFlash
 *
 * PARAMETERS : None
 *
 * RETURN     : None
 *==========================================================================*/
QCameraFlash::QCameraFlash() : m_callbacks(NULL)
{
    memset(&m_flashOn, 0, sizeof(m_flashOn));
    memset(&m_cameraOpen, 0, sizeof(m_cameraOpen));
    for (int pos = 0; pos < MM_CAMERA_MAX_NUM_SENSORS; pos++) {
        m_flashFds[pos] = -1;
    }
}

/*===========================================================================
 * FUNCTION   : ~QCameraFlash
 *
 * DESCRIPTION: deconstructor of QCameraFlash
 *
 * PARAMETERS : None
 *
 * RETURN     : None
 *==========================================================================*/
QCameraFlash::~QCameraFlash()
{
    for (int pos = 0; pos < MM_CAMERA_MAX_NUM_SENSORS; pos++) {
        if (m_flashFds[pos] >= 0)
            {
                setFlashMode(pos, false);
                close(m_flashFds[pos]);
                m_flashFds[pos] = -1;
            }
    }
}

/*===========================================================================
 * FUNCTION   : registerCallbacks
 *
 * DESCRIPTION: provide flash module with reference to callbacks to framework
 *
 * PARAMETERS : None
 *
 * RETURN     : None
 *==========================================================================*/
int32_t QCameraFlash::registerCallbacks(
        const camera_module_callbacks_t* callbacks)
{
    int32_t retVal = 0;
    m_callbacks = callbacks;
    return retVal;
}

/*===========================================================================
 * FUNCTION   : initFlash
 *
 * DESCRIPTION: Reserve and initialize the flash unit associated with a
 *              given camera id. This function is blocking until the
 *              operation completes or fails. Each flash unit can be "inited"
 *              by only one process at a time.
 *
 * PARAMETERS :
 *   @camera_id : Camera id of the flash.
 *
 * RETURN     :
 *   0        : success
 *   -EBUSY   : The flash unit or the resource needed to turn on the
 *              the flash is busy, typically because the flash is
 *              already in use.
 *   -EINVAL  : No flash present at camera_id.
 *==========================================================================*/
int32_t QCameraFlash::initFlash(const int camera_id)
{
    int32_t retVal = 0;
    bool hasFlash = false;
    char flashNode[QCAMERA_MAX_FILEPATH_LENGTH];
    char flashPath[QCAMERA_MAX_FILEPATH_LENGTH] = "/dev/";

    if (camera_id < 0 || camera_id >= MM_CAMERA_MAX_NUM_SENSORS) {
        LOGE("Invalid camera id: %d", camera_id);
        return -EINVAL;
    }

    QCamera3HardwareInterface::getFlashInfo(camera_id,
            hasFlash,
            flashNode);

    strlcat(flashPath,
            flashNode,
            sizeof(flashPath));

    if (!hasFlash) {
        LOGE("No flash available for camera id: %d",
                camera_id);
        retVal = -EINVAL;
    } else if (m_cameraOpen[camera_id]) {
        LOGE("Camera in use for camera id: %d",
                camera_id);
        retVal = -EBUSY;
    } else if (m_flashFds[camera_id] >= 0) {
        LOGD("Flash is already inited for camera id: %d",
                camera_id);
    } else {
        m_flashFds[camera_id] = open(flashPath, O_RDWR | O_NONBLOCK);

        if (m_flashFds[camera_id] < 0) {
            LOGE("Unable to open node '%s'",
                    flashPath);
            retVal = -EBUSY;
        } else {
            struct msm_flash_cfg_data_t cfg;
            struct msm_flash_init_info_t init_info;
#ifdef F_PANTECH_CAMERA_FLASH_LM3559
            struct msm_sensor_power_setting_array *power_setting_array;
            struct msm_camera_i2c_reg_setting_array *lm3559_setting_on;            
            unsigned short flash_power_setting[] = {SENSOR_GPIO_IOVDD_EN, 
                                                    SENSOR_GPIO_FL_EN, 
                                                    SENSOR_GPIO_FL_NOW};
            unsigned short flash_init_setting[] = {0x10, 0x18};
#endif
            memset(&cfg, 0, sizeof(struct msm_flash_cfg_data_t));
            memset(&init_info, 0, sizeof(struct msm_flash_init_info_t));
#ifdef F_PANTECH_CAMERA_FLASH_LM3559
            init_info.flash_driver_type = FLASH_DRIVER_I2C;
            init_info.slave_addr = 0xa6;
            init_info.i2c_freq_mode = I2C_STANDARD_MODE;
            power_setting_array = (struct msm_sensor_power_setting_array *)malloc(sizeof(*power_setting_array));
            lm3559_setting_on = (struct msm_camera_i2c_reg_setting_array *)malloc(sizeof(*lm3559_setting_on));
            if(!power_setting_array || !lm3559_setting_on)
            {
              ALOGE("flash power_setting mem NULL!!");
              return -EINVAL;
            }
            power_setting_array->size = (sizeof(flash_power_setting) / sizeof((flash_power_setting)[0]));
            power_setting_array->size_down = (sizeof(flash_power_setting) / sizeof((flash_power_setting)[0]));
            for(int i = 0; i<power_setting_array->size; i++)
            {
              power_setting_array->power_setting_a[i].seq_type = SENSOR_GPIO;
              power_setting_array->power_setting_a[i].seq_val = flash_power_setting[i];
              power_setting_array->power_setting_a[i].config_val = 2; /*GPIO_OUT_HIGH*/
              power_setting_array->power_setting_a[i].delay = 1;
              power_setting_array->power_down_setting_a[i].seq_type = SENSOR_GPIO;
              power_setting_array->power_down_setting_a[i].seq_val = flash_power_setting[i];
              power_setting_array->power_down_setting_a[i].config_val = 0; /*GPIO_OUT_LOW*/
              power_setting_array->power_down_setting_a[i].delay = 0;
            }

            lm3559_setting_on->addr_type = MSM_CAMERA_I2C_BYTE_ADDR;
            lm3559_setting_on->data_type = MSM_CAMERA_I2C_BYTE_DATA;
            lm3559_setting_on->delay = 0;
            lm3559_setting_on->size = 1;
            lm3559_setting_on->reg_setting_a[0].reg_addr = flash_init_setting[0];
            lm3559_setting_on->reg_setting_a[0].reg_data = flash_init_setting[1];
            lm3559_setting_on->reg_setting_a[0].delay = 0;
            init_info.power_setting_array = power_setting_array;
            init_info.settings = lm3559_setting_on;            
#else
            init_info.flash_driver_type = FLASH_DRIVER_DEFAULT;
#endif
            ALOGE("flashLight init %d type %d",__LINE__,init_info.flash_driver_type);
            cfg.cfg.flash_init_info = &init_info;
            cfg.cfg_type = CFG_FLASH_INIT;
            retVal = ioctl(m_flashFds[camera_id],
                    VIDIOC_MSM_FLASH_CFG,
                    &cfg);
            if (retVal < 0) {
                LOGE("Unable to init flash for camera id: %d",
                        camera_id);
                close(m_flashFds[camera_id]);
                m_flashFds[camera_id] = -1;
            }

            /* wait for PMIC to init */
            usleep(5000);
        }
    }

    LOGD("X, retVal = %d", retVal);
    return retVal;
}

/*===========================================================================
 * FUNCTION   : setFlashMode
 *
 * DESCRIPTION: Turn on or off the flash associated with a given handle.
 *              This function is blocking until the operation completes or
 *              fails.
 *
 * PARAMETERS :
 *   @camera_id  : Camera id of the flash
 *   @on         : Whether to turn flash on (true) or off (false)
 *
 * RETURN     :
 *   0        : success
 *   -EINVAL  : No camera present at camera_id, or it is not inited.
 *   -EALREADY: Flash is already in requested state
 *==========================================================================*/
int32_t QCameraFlash::setFlashMode(const int camera_id, const bool mode)
{
    int32_t retVal = 0;
    struct msm_flash_cfg_data_t cfg;

    if (camera_id < 0 || camera_id >= MM_CAMERA_MAX_NUM_SENSORS) {
        LOGE("Invalid camera id: %d", camera_id);
        retVal = -EINVAL;
    } else if (mode == m_flashOn[camera_id]) {
        LOGD("flash %d is already in requested state: %d",
                camera_id,
                mode);
        retVal = -EALREADY;
    } else if (m_flashFds[camera_id] < 0) {
        LOGE("called for uninited flash: %d", camera_id);
        retVal = -EINVAL;
    }  else {
#ifdef F_PANTECH_CAMERA_FLASH_LM3559
        struct msm_camera_i2c_reg_setting_array *flash_low_settings;
        struct msm_camera_i2c_reg_setting_array *flash_off_settings;
        unsigned short flash_low_setting[2][2] = {{0x10, 0x1A},{0xA0, 0x1B}};
        unsigned short flash_off_setting[] = {0x10, 0x00};
        flash_low_settings = (struct msm_camera_i2c_reg_setting_array *)malloc(sizeof(*flash_low_settings));
        flash_off_settings = (struct msm_camera_i2c_reg_setting_array *)malloc(sizeof(*flash_off_settings));   
        if(!flash_low_settings || !flash_off_settings)
        {
          ALOGE("flash_settings mem NULL!!");
          return -EINVAL;
        }

        flash_low_settings->addr_type = flash_off_settings->addr_type = MSM_CAMERA_I2C_BYTE_ADDR;
        flash_low_settings->data_type = flash_off_settings->data_type = MSM_CAMERA_I2C_BYTE_DATA;
        flash_low_settings->delay = flash_off_settings->delay = 0;
        flash_low_settings->size = (sizeof(flash_low_setting) / sizeof((flash_low_setting)[0]));
        for(int i=0;i<flash_low_settings->size;i++)
        {
          flash_low_settings->reg_setting_a[i].reg_addr = flash_low_setting[i][0];
          flash_low_settings->reg_setting_a[i].reg_data = flash_low_setting[i][1];
          flash_low_settings->reg_setting_a[i].delay = 0;
        }        
        
        flash_off_settings->size = 1;
        flash_off_settings->reg_setting_a[0].reg_addr = flash_off_setting[0];
        flash_off_settings->reg_setting_a[0].reg_data = flash_off_setting[1];
        flash_off_settings->reg_setting_a[0].delay = 0;
#endif
        memset(&cfg, 0, sizeof(struct msm_flash_cfg_data_t));
        for (int i = 0; i < MAX_LED_TRIGGERS; i++)
            cfg.flash_current[i] = QCAMERA_TORCH_CURRENT_VALUE;
        cfg.cfg_type = mode ? CFG_FLASH_LOW: CFG_FLASH_OFF;
#ifdef F_PANTECH_CAMERA_FLASH_LM3559
        cfg.cfg.settings = mode ? flash_low_settings : flash_off_settings;
#endif
        ALOGE("set FlashLight Mode %d  type %d", mode, cfg.cfg_type);

        retVal = ioctl(m_flashFds[camera_id],
                        VIDIOC_MSM_FLASH_CFG,
                        &cfg);
        if (retVal < 0) {
            LOGE("Unable to change flash mode to %d for camera id: %d",
                     mode, camera_id);
        } else
        {
            m_flashOn[camera_id] = mode;
        }
    }
    return retVal;
}

/*===========================================================================
 * FUNCTION   : deinitFlash
 *
 * DESCRIPTION: Release the flash unit associated with a given camera
 *              position. This function is blocking until the operation
 *              completes or fails.
 *
 * PARAMETERS :
 *   @camera_id : Camera id of the flash.
 *
 * RETURN     :
 *   0        : success
 *   -EINVAL  : No camera present at camera_id or not inited.
 *==========================================================================*/
int32_t QCameraFlash::deinitFlash(const int camera_id)
{
    int32_t retVal = 0;

    if (camera_id < 0 || camera_id >= MM_CAMERA_MAX_NUM_SENSORS) {
        LOGE("Invalid camera id: %d", camera_id);
        retVal = -EINVAL;
    } else if (m_flashFds[camera_id] < 0) {
        LOGE("called deinitFlash for uninited flash");
        retVal = -EINVAL;
    } else {
        setFlashMode(camera_id, false);

        struct msm_flash_cfg_data_t cfg;
        cfg.cfg_type = CFG_FLASH_RELEASE;
        retVal = ioctl(m_flashFds[camera_id],
                VIDIOC_MSM_FLASH_CFG,
                &cfg);
        if (retVal < 0) {
            LOGE("Failed to release flash for camera id: %d",
                    camera_id);
        }

        close(m_flashFds[camera_id]);
        m_flashFds[camera_id] = -1;
    }

    return retVal;
}

/*===========================================================================
 * FUNCTION   : reserveFlashForCamera
 *
 * DESCRIPTION: Give control of the flash to the camera, and notify
 *              framework that the flash has become unavailable.
 *
 * PARAMETERS :
 *   @camera_id : Camera id of the flash.
 *
 * RETURN     :
 *   0        : success
 *   -EINVAL  : No camera present at camera_id or not inited.
 *   -ENOSYS  : No callback available for torch_mode_status_change.
 *==========================================================================*/
int32_t QCameraFlash::reserveFlashForCamera(const int camera_id)
{
    int32_t retVal = 0;

    if (camera_id < 0 || camera_id >= MM_CAMERA_MAX_NUM_SENSORS) {
        LOGE("Invalid camera id: %d", camera_id);
        retVal = -EINVAL;
    } else if (m_cameraOpen[camera_id]) {
        LOGD("Flash already reserved for camera id: %d",
                camera_id);
    } else {
        if (m_flashOn[camera_id]) {
            setFlashMode(camera_id, false);
            deinitFlash(camera_id);
        }
        m_cameraOpen[camera_id] = true;

        bool hasFlash = false;
        char flashNode[QCAMERA_MAX_FILEPATH_LENGTH];

        QCamera3HardwareInterface::getFlashInfo(camera_id,
                hasFlash,
                flashNode);

        if (m_callbacks == NULL ||
                m_callbacks->torch_mode_status_change == NULL) {
            LOGE("Callback is not defined!");
            retVal = -ENOSYS;
        } else if (!hasFlash) {
            LOGD("Suppressing callback "
                    "because no flash exists for camera id: %d",
                    camera_id);
        } else {
            char cameraIdStr[STRING_LENGTH_OF_64_BIT_NUMBER];
            snprintf(cameraIdStr, STRING_LENGTH_OF_64_BIT_NUMBER,
                    "%d", camera_id);
            m_callbacks->torch_mode_status_change(m_callbacks,
                    cameraIdStr,
                    TORCH_MODE_STATUS_NOT_AVAILABLE);
        }
    }

    return retVal;
}

/*===========================================================================
 * FUNCTION   : releaseFlashFromCamera
 *
 * DESCRIPTION: Release control of the flash from the camera, and notify
 *              framework that the flash has become available.
 *
 * PARAMETERS :
 *   @camera_id : Camera id of the flash.
 *
 * RETURN     :
 *   0        : success
 *   -EINVAL  : No camera present at camera_id or not inited.
 *   -ENOSYS  : No callback available for torch_mode_status_change.
 *==========================================================================*/
int32_t QCameraFlash::releaseFlashFromCamera(const int camera_id)
{
    int32_t retVal = 0;

    if (camera_id < 0 || camera_id >= MM_CAMERA_MAX_NUM_SENSORS) {
        LOGE("Invalid camera id: %d", camera_id);
        retVal = -EINVAL;
    } else if (!m_cameraOpen[camera_id]) {
        LOGD("Flash not reserved for camera id: %d",
                camera_id);
    } else {
        m_cameraOpen[camera_id] = false;

        bool hasFlash = false;
        char flashNode[QCAMERA_MAX_FILEPATH_LENGTH];

        QCamera3HardwareInterface::getFlashInfo(camera_id,
                hasFlash,
                flashNode);

        if (m_callbacks == NULL ||
                m_callbacks->torch_mode_status_change == NULL) {
            LOGE("Callback is not defined!");
            retVal = -ENOSYS;
        } else if (!hasFlash) {
            LOGD("Suppressing callback "
                    "because no flash exists for camera id: %d",
                    camera_id);
        } else {
            char cameraIdStr[STRING_LENGTH_OF_64_BIT_NUMBER];
            snprintf(cameraIdStr, STRING_LENGTH_OF_64_BIT_NUMBER,
                    "%d", camera_id);
            m_callbacks->torch_mode_status_change(m_callbacks,
                    cameraIdStr,
                    TORCH_MODE_STATUS_AVAILABLE_OFF);
        }
    }

    return retVal;
}

}; // namespace qcamera
