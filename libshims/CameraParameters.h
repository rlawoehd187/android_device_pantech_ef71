/*
 * Copyright (C) 2017 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

namespace android {

class CameraParameters
{
public:
    static const char FOCUS_MODE_MANUAL_POSITION[]; 
    static const char KEY_APP_MASK[]; 
    static const char WHITE_BALANCE_MANUAL_CCT[]; 
    static const char SKY_IPL_FIXED_DOT[];
    static const char SKY_IPL_TEXT_BB_B[];
    static const char SKY_IPL_TEXT_WB_B[];
    static const char SKY_IPL_TEXT_WB_C[];
    static const char SKY_IPL_COLOR_DOT_BLACK[];
    static const char SKY_IPL_COLOR_DOT_WHITE[];
    static const char SKY_SKETCH_C[];
    static const char SKY_SKETCH_M[];
    static const char SKY_IPL_SKETCH_C[];
    static const char SKY_IPL_SKETCH_M[];
    static const char SKY_IPL_DITHER_BW_C[];
    static const char SKY_IPL_DITHER_BW_M[];
    static const char SKY_IPL_SOLARIZE[];
    static const char SKY_IPL_EMBOSS[];
    static const char SKY_IPL_NEON[];
    static const char SKY_IPL_COLOR_CHANGE_0[];
    static const char SKY_IPL_COLOR_CHANGE_1[];
    static const char SKY_IPL_COLOR_CHANGE_2[];
    static const char SKY_IPL_COLOR_CHANGE_3[];
    static const char SKY_IPL_SKIN_DETECTOR[];
    static const char SKY_IPL_EFFECT_EXT_1[];
    static const char SKY_IPL_EFFECT_EXT_2[];
    static const char SKY_IPL_EFFECT_EXT_3[];
    static const char SKY_IPL_EFFECT_EXT_4[];
    static const char SKY_CARTOON_C[];
    static const char SKY_CARTOON_M[];
    static const char SKY_IPL_SKY_EFFECT[];
    static const char SKY_POSTER_CARTOON_C[];
    static const char SKY_POSTER_CARTOON_M[];
    static const char SKY_IPL_POSTER_CARTOON_C[];
    static const char SKY_IPL_POSTER_CARTOON_M[];
    static const char SKY_IPL_CARTOON_C[];
    static const char SKY_IPL_CARTOON_M[];
    static const char VEGAEYE_ON[];
    static const char VEGAEYE_OFF[];
    static const char KEY_SKY_EFFECT_MODE[];
    static const char KEY_SKY_IPL_VALUE_3[];
    static const char KEY_VEGAEYE[];
    static const char KEY_OJT[];
    static const char OJT_OFF[];
    static const char OJT_ON[];
    static const char CAMNOTE_AUTO[];
    static const char KEY_SUPPORTED_OJT[];
    static const char FLASH_MODE_ZSL_TORCH_AUTO[];
    static const char SKY_IPL_CAM_CARTOON[];
    static const char SKY_IPL_WIDGET_CARTOON[];
    static const char SKY_IPL_SKETCH[];
    static const char KEY_FLASH[];
    static const char KEY_HDR[];
    static const char KEY_SUPPORTED_HDR[];
    static const char HDR_OFF[];
    static const char HDR_ON[];
    static const char KEY_HDR_SAVING_MODE[];
    static const char HDR_SETTING_MODE_OFF[];
    static const char HDR_SETTING_MODE_ON[];
    static const char KEY_SKY_COLOREXT_COORDINATES_R[];
    static const char KEY_SKY_COLOREXT_COORDINATES_G[];
    static const char KEY_SKY_COLOREXT_COORDINATES_B[];
    static const char KEY_SKY_COLOREXTRACTION[];
    static const char KEY_SKY_IPL_MODE[];
    static const char SKY_IPL_OFF[];
    static const char SKY_COLOREXT_OFF[];
    static const char KEY_SUPPORTED_SKY_COLOREXTRACTION[];
    static const char KEY_SKY_COLOREXT_COORDINATES[];
    static const char KEY_SKY_COLOREXT_RGB_R[];
    static const char KEY_SKY_COLOREXT_RGB_G[];
    static const char KEY_SKY_COLOREXT_RGB_B[];
    static const char SKY_COLOREXT_TOUCH[];
    static const char SKY_COLOREXT_RED[];
    static const char SKY_COLOREXT_GREEN[];
    static const char SKY_COLOREXT_BLUE[];
    static const char SKY_COLOREXT_YELLOW[];
    static const char SKY_IPL_CAMNOTE[];
    static const char SKY_IPL_BEAUTY[];
    static const char SKY_IPL_MINIATURE[];
    static const char SKY_IPL_CARTOON[];
    static const char SKY_IPL_CARTOON_FRONT[];
    static const char KEY_SHUTTER_SOUND[];
    static const char KEY_CAMNOTE[];
    static const char KEY_CAMNOTE_MODE[];
    static const char KEY_VT[];
    static const char VT_OFF[];
    static const char CAMNOTE_WB_C[];
    static const char CAMNOTE_OFF[];
    static const char CAMNOTE_ON[];
    static const char CAMNOTE_WB_B[];
    static const char CAMNOTE_BL_B[];
    static const char CAMNOTE_NORMAL[];
    static const char EFFECT_WHITEBOARD_C[];
    static const char EFFECT_BLACKBOARD_C[];
    static const char KEY_SKY_IPL_VALUE_2[];
    static const char KEY_SKY_IPL_VALUE_1[];
    static const char KEY_FOCUS_COORDINATES[];
    static const char KEY_SUPPORTED_SHUTTER_SOUND[];
    static const char KEY_SUPPORTED_MULTISHOT[];
    static const char KEY_SUPPORTED_REFLECT[];
    static const char KEY_REMOTE_MODE[];
    static const char SCENE_MODE_INDOOR[];
    static const char SCENE_MODE_TEXT[];
    static const char FLASH_MODE_TORCH_FLASH[];
    static const char SHUTTER_SOUND_OFF[];
    static const char SHUTTER_SOUND_ON[];
    static const char HDVT_ON[];
    static const char AUTO_EXPOSURE_OFF[];
    static const char WHITE_BALANCE_OFF[];
    static const char REFLECT_MIRROR_WATER[];
    static const char H324MVT_ON[];
    static const char KEY_REFLECT[];
    static const char REFLECT_OFF[];
    static const char KEY_ANTISHAKE[];
    static const char ANTISHAKE_ON[];
    static const char ANTISHAKE_OFF[];
    static const char KEY_MULTISHOT[];
    static const char MULTISHOT_OFF[];
    static const char MULTISHOT_ON[];
    static const char REFLECT_WATER[];
    static const char KEY_FOCUS_STEP[];
    static const char REFLECT_MIRROR[];
    static const char EFFECT_CONTRAST[];
    static const char FOCUS_MODE_SPOT[];
    static const char FOCUS_MODE_MANUAL[];
    static const char SCENE_MODE_DAWN[];
    static const char SCENE_MODE_AUTUMN[];
    static const char FACE_FILTER_KISS[];
    static const char FACE_FILTER_LOMO[];
    static const char FACE_FILTER_MONO[];
    static const char FACE_FILTER_POOH[];
    static const char FACE_FILTER_SICK[];
    static const char FACE_FILTER_SNOW[];
    static const char FACE_FILTER_TEAR[];
    static const char FACE_FILTER_ANGRY[];
    static const char FACE_FILTER_CROWN[];
    static const char FACE_FILTER_PUNCH[];
    static const char FACE_FILTER_ABSURD[];
    static const char FACE_FILTER_HEATUP[];
    static const char FACE_FILTER_MOSAIC[];
    static const char FACE_FILTER_PIRATE[];
    static const char FACE_FILTER_BIGHEAD[];
    static const char FACE_FILTER_CONCAVE[];
    static const char FACE_FILTER_FISHEYE[];
    static const char FACE_FILTER_VERTIGO[];
    static const char FACE_FILTER_OUTFOCUS[];
    static const char FACE_FILTER_GENTLEMAN[];
    static const char FACE_FILTER_SHEEPHOOD[];
    static const char FACE_FILTER_BEAUTYBLUR[];
    static const char FACE_FILTER_FACEDETECT[];
    static const char FACE_FILTER_RADIALBLUR[];
    static const char FACE_FILTER_FACIALCOLOR[];
    static const char FACE_FILTER_SMILEDETECT[];
    static const char FACE_FILTER_SELFSHOTHELPER[];
    static const char FACE_FILTER_OFF[];
    static const char KEY_FACE_FILTER[];
    static const char KEY_FACE_FILTER_ROTATION[];
    static const char KEY_FACE_FILTER_RECT[];
    static const char KEY_FACE_SMILE_SCORE[];
    static const char KEY_FACE_SELFSHOT_NUM[];
    static const char KEY_SUPPORTED_ANTISHAKE[];
    static const char KEY_SUPPORTED_FACE_FILTER[];
    static const char LGTVT_ON[];
    static const char KEY_VTS[];
    static const char SCENE_MODE_OFF[];
    static const char SCENE_MODE_CUSTOM[];
    static const char VTS_OFF[];
    static const char VTS_ON[];
    static const char LLS_OFF[];
    static const char LLS_ON[];
    static const char SKY_IPL_MONO_DOT[];
    int isRunning();
    int getOlaRotation() const;
    void getFaceFilterRect(int *x, int *y) const;
    void getFocusCoordinates(int *x, int *y) const;
    void setFocusCoordinates(int x, int y);
    void setFaceFilterRect(int width, int height);
    void setReflect(int reflect);
    void getColorExtractionCoordinates(int *x, int *y) const;
    void setColorExtractionCoordinates(int x, int y);
    void getColorExtractionRGB_B(int *x, int *y) const;
    void setColorExtractionRGB_B(int x, int y);
    void getColorExtractionRGB_G(int *x, int *y) const;
    void setColorExtractionRGB_G(int x, int y);
    void getColorExtractionRGB_R(int *x, int *y) const;
    void setColorExtractionRGB_R(int x, int y);
};

}; // namespace android
