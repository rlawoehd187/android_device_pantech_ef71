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

#include "CameraParameters.h"

namespace android {
    const char CameraParameters::FOCUS_MODE_MANUAL_POSITION[] = "manual";
    const char CameraParameters::KEY_APP_MASK[] = "app-mask";
    const char CameraParameters::WHITE_BALANCE_MANUAL_CCT[] = "manual-cct";
    const char CameraParameters::SKY_SKETCH_C[] = "sky-sketch-c";
    const char CameraParameters::SKY_SKETCH_M[] = "sky-sketch-m";
    const char CameraParameters::SKY_IPL_SKETCH_C[] = "pantech-ipl-sketch-c";
    const char CameraParameters::SKY_IPL_SKETCH_M[] = "pantech-ipl-sketch-m";
    const char CameraParameters::SKY_IPL_DITHER_BW_C[] = "pantech-ipl-ditherbw-c";
    const char CameraParameters::SKY_IPL_DITHER_BW_M[] = "pantech-ipl-ditherbw-m";
    const char CameraParameters::SKY_IPL_SOLARIZE[] = "pantech-ipl-solariez";
    const char CameraParameters::SKY_IPL_EMBOSS[] = "pantech-ipl-emboss";
    const char CameraParameters::SKY_IPL_NEON[] = "pantech-ipl-neon";
    const char CameraParameters::SKY_IPL_COLOR_CHANGE_0[] = "pantech-ipl-colorchange-0";
    const char CameraParameters::SKY_IPL_COLOR_CHANGE_1[] = "pantech-ipl-colorchange-1";
    const char CameraParameters::SKY_IPL_COLOR_CHANGE_2[] = "pantech-ipl-colorchange-2";
    const char CameraParameters::SKY_IPL_COLOR_CHANGE_3[] = "pantech-ipl-colorchange-3";
    const char CameraParameters::SKY_IPL_SKIN_DETECTOR[] = "pantech-ipl-skincolorextrac";
    const char CameraParameters::SKY_IPL_EFFECT_EXT_1[] = "pantech-ipl-effect-ext-1";
    const char CameraParameters::SKY_IPL_EFFECT_EXT_2[] = "pantech-ipl-effect-ext-2";
    const char CameraParameters::SKY_IPL_EFFECT_EXT_3[] = "pantech-ipl-effect-ext-3";
    const char CameraParameters::SKY_IPL_EFFECT_EXT_4[] = "pantech-ipl-effect-ext-4";
    const char CameraParameters::SKY_CARTOON_C[] = "sky-cartoon-c";
    const char CameraParameters::SKY_CARTOON_M[] = "sky-cartoon-m";
    const char CameraParameters::SKY_IPL_SKY_EFFECT[] = "pantech-ipl-sky-effect";
    const char CameraParameters::SKY_POSTER_CARTOON_C[] = "poster-cartoon-c";
    const char CameraParameters::SKY_POSTER_CARTOON_M[] = "poster-cartoon-m";
    const char CameraParameters::SKY_IPL_POSTER_CARTOON_C[] = "pantech-ipl-poster-cartoon-c";
    const char CameraParameters::SKY_IPL_POSTER_CARTOON_M[] = "pantech-ipl-poster-cartoon-m";
    const char CameraParameters::SKY_IPL_CARTOON_C[] = "pantech-ipl-cartoon-c";
    const char CameraParameters::SKY_IPL_CARTOON_M[] = "pantech-ipl-cartoon-m";
    const char CameraParameters::VEGAEYE_OFF[] = "vegaeye-off";
    const char CameraParameters::VEGAEYE_ON[] = "vegaeye-on";
    const char CameraParameters::KEY_SKY_EFFECT_MODE[] = "pantech-effect-mode";
    const char CameraParameters::KEY_SKY_IPL_VALUE_3[] = "pantech-ipl3";
    const char CameraParameters::KEY_VEGAEYE[] = "vegaeye";
    const char CameraParameters::KEY_ANTISHAKE[] = "pantech-antishake";
    const char CameraParameters::KEY_OJT[] = "pantech-ojt";
    const char CameraParameters::OJT_OFF[] = "off";
    const char CameraParameters::OJT_ON[] = "on";
    const char CameraParameters::CAMNOTE_AUTO[] = "auto";
    const char CameraParameters::KEY_SUPPORTED_OJT[] = "pantech-supported-ojt";
    const char CameraParameters::FLASH_MODE_ZSL_TORCH_AUTO[] = "torch-zsl-auto";
    const char CameraParameters::SKY_IPL_CAM_CARTOON[] = "pantech-ipl-cam-cartoon";
    const char CameraParameters::SKY_IPL_WIDGET_CARTOON[] = "pantech-ipl-widget-cartoon";
    const char CameraParameters::SKY_IPL_SKETCH[] = "pantech-ipl-sketch";
    const char CameraParameters::KEY_FLASH[] = "pantech-flash";
    const char CameraParameters::KEY_HDR_SAVING_MODE[] = "hdr-saving-mode";
    const char CameraParameters::HDR_SETTING_MODE_OFF[] = "hdr-setting-mode-off";
    const char CameraParameters::HDR_SETTING_MODE_ON[] = "hdr-setting-mode-on";
    const char CameraParameters::KEY_HDR[] = "hdr";
    const char CameraParameters::KEY_SUPPORTED_HDR[] = "hdr-values";
    const char CameraParameters::HDR_ON[] = "hdr-on";
    const char CameraParameters::HDR_OFF[] = "hdr-off";
    const char CameraParameters::KEY_SKY_COLOREXT_COORDINATES_R[] = "pantech-color-extraction-coordinates-r";
    const char CameraParameters::KEY_SKY_COLOREXT_COORDINATES_G[] = "pantech-color-extraction-coordinates-g";
    const char CameraParameters::KEY_SKY_COLOREXT_COORDINATES_B[] = "pantech-color-extraction-coordinates-b";
    const char CameraParameters::KEY_SKY_COLOREXTRACTION[] = "pantech-colorextraction";
    const char CameraParameters::KEY_SKY_IPL_MODE[] = "pantech-ipl-mode";
    const char CameraParameters::SKY_IPL_OFF[] = "pantech-ipl-off";
    const char CameraParameters::SKY_COLOREXT_OFF[] = "off";
    const char CameraParameters::KEY_SUPPORTED_SKY_COLOREXTRACTION[] = "T";
    const char CameraParameters::KEY_SKY_COLOREXT_COORDINATES[] = "T";
    const char CameraParameters::KEY_SKY_COLOREXT_RGB_R[] = "pantech-colorextraction-rgb-r";
    const char CameraParameters::KEY_SKY_COLOREXT_RGB_G[] = "pantech-colorextraction-rgb-g";
    const char CameraParameters::KEY_SKY_COLOREXT_RGB_B[] = "pantech-colorextraction-rgb-b";
    const char CameraParameters::SKY_COLOREXT_TOUCH[] = "colorext-touch";
    const char CameraParameters::SKY_COLOREXT_RED[] = "colorext-red";
    const char CameraParameters::SKY_COLOREXT_GREEN[] = "colorext-green";
    const char CameraParameters::SKY_COLOREXT_BLUE[] = "colorext-blue";
    const char CameraParameters::SKY_COLOREXT_YELLOW[] = "colorext-yellow";
    const char CameraParameters::SKY_IPL_CAMNOTE[] = "pantech-ipl-camnote";
    const char CameraParameters::SKY_IPL_BEAUTY[] = "pantech-ipl-beauty";
    const char CameraParameters::SKY_IPL_MINIATURE[] = "pantech-ipl-miniature";
    const char CameraParameters::SKY_IPL_CARTOON[] = "pantech-ipl-cartoon";
    const char CameraParameters::SKY_IPL_CARTOON_FRONT[] = "cartoon-front";
    const char CameraParameters::KEY_SHUTTER_SOUND[] = "shutter-sound";
    const char CameraParameters::KEY_CAMNOTE[] = "camnote";
    const char CameraParameters::KEY_CAMNOTE_MODE[] = "camnote-mode";
    const char CameraParameters::KEY_VT[] = "pantech-vt";
    const char CameraParameters::KEY_MULTISHOT[] = "pantech-multishot";
    const char CameraParameters::MULTISHOT_OFF[] = "off";
    const char CameraParameters::MULTISHOT_ON[] = "on";
    const char CameraParameters::VT_OFF[] = "off";
    const char CameraParameters::REFLECT_OFF[] = "off";
    const char CameraParameters::CAMNOTE_WB_C[] = "wb-c";
    const char CameraParameters::CAMNOTE_OFF[] = "off";
    const char CameraParameters::CAMNOTE_ON[] = "on";
    const char CameraParameters::CAMNOTE_WB_B[] = "wb-b";
    const char CameraParameters::CAMNOTE_BL_B[] = "bl-b";
    const char CameraParameters::CAMNOTE_NORMAL[] = "normal";
    const char CameraParameters::EFFECT_WHITEBOARD_C[] = "whiteboard-c";
    const char CameraParameters::EFFECT_BLACKBOARD_C[] = "blackboard-c";
    const char CameraParameters::KEY_SKY_IPL_VALUE_2[] = "value-2";
    const char CameraParameters::KEY_SKY_IPL_VALUE_1[] = "value-1";
    const char CameraParameters::KEY_REFLECT[] = "pantech-reflect";
    const char CameraParameters::KEY_FOCUS_STEP[] = "pantech-focus-step";
    const char CameraParameters::KEY_FOCUS_COORDINATES[] = "pantech-focus-coordinates";
    const char CameraParameters::KEY_SUPPORTED_SHUTTER_SOUND[] = "pantech-supported-shutter-sound";
    const char CameraParameters::KEY_SUPPORTED_MULTISHOT[] = "pantech-supported-multishot";
    const char CameraParameters::KEY_SUPPORTED_REFLECT[] = "pantech-supported-reflect";
    const char CameraParameters::KEY_REMOTE_MODE[] = "pantech-remote";
    const char CameraParameters::SCENE_MODE_INDOOR[] = "indoor";
    const char CameraParameters::SCENE_MODE_TEXT[] = "text";
    const char CameraParameters::FLASH_MODE_TORCH_FLASH[] = "tourch-flash";
    const char CameraParameters::SHUTTER_SOUND_OFF[] = "off";
    const char CameraParameters::SHUTTER_SOUND_ON[] = "on";
    const char CameraParameters::H324MVT_ON[] = "on";
    const char CameraParameters::HDVT_ON[] = "off";
    const char CameraParameters::AUTO_EXPOSURE_OFF[] = "off";
    const char CameraParameters::WHITE_BALANCE_OFF[] = "off";
    const char CameraParameters::REFLECT_MIRROR[] = "mirror";
    const char CameraParameters::REFLECT_WATER[] = "water";
    const char CameraParameters::REFLECT_MIRROR_WATER[] = "mirror-water";
    const char CameraParameters::ANTISHAKE_ON[] = "on";
    const char CameraParameters::ANTISHAKE_OFF[] = "off";
    const char CameraParameters::EFFECT_CONTRAST[] = "contrast";
    const char CameraParameters::FOCUS_MODE_SPOT[] = "spot";
    const char CameraParameters::FOCUS_MODE_MANUAL[] = "manual";
    const char CameraParameters::SCENE_MODE_DAWN[] = "dawn";
    const char CameraParameters::SCENE_MODE_AUTUMN[] = "autumn";
    const char CameraParameters::FACE_FILTER_KISS[] = "kiss";
    const char CameraParameters::FACE_FILTER_LOMO[] = "lomo";
    const char CameraParameters::FACE_FILTER_MONO[] = "mono";
    const char CameraParameters::FACE_FILTER_POOH[] = "pooh";
    const char CameraParameters::FACE_FILTER_SICK[] = "sick";
    const char CameraParameters::FACE_FILTER_SNOW[] = "snow";
    const char CameraParameters::FACE_FILTER_TEAR[] = "tear";
    const char CameraParameters::FACE_FILTER_ANGRY[] = "angry";
    const char CameraParameters::FACE_FILTER_CROWN[] = "crown";
    const char CameraParameters::FACE_FILTER_PUNCH[] = "punch";
    const char CameraParameters::FACE_FILTER_ABSURD[] = "absurd";
    const char CameraParameters::FACE_FILTER_HEATUP[] = "heatup";
    const char CameraParameters::FACE_FILTER_MOSAIC[] = "mosaic";
    const char CameraParameters::FACE_FILTER_PIRATE[] = "priate";
    const char CameraParameters::FACE_FILTER_BIGHEAD[] = "bighead";
    const char CameraParameters::FACE_FILTER_CONCAVE[] = "concave";
    const char CameraParameters::FACE_FILTER_FISHEYE[] = "fisheye";
    const char CameraParameters::FACE_FILTER_VERTIGO[] = "vertigo";
    const char CameraParameters::FACE_FILTER_OUTFOCUS[] = "outfocus";
    const char CameraParameters::FACE_FILTER_GENTLEMAN[] = "gentleman";
    const char CameraParameters::FACE_FILTER_SHEEPHOOD[] = "sheephood";
    const char CameraParameters::FACE_FILTER_BEAUTYBLUR[] = "beautyblur";
    const char CameraParameters::FACE_FILTER_FACEDETECT[] = "facedetect";
    const char CameraParameters::FACE_FILTER_RADIALBLUR[] = "radialblur";
    const char CameraParameters::FACE_FILTER_FACIALCOLOR[] = "facialcolor";
    const char CameraParameters::FACE_FILTER_SMILEDETECT[] = "smiledetect";
    const char CameraParameters::FACE_FILTER_SELFSHOTHELPER[] = "selfshothelper";
    const char CameraParameters::FACE_FILTER_OFF[] = "off";
    const char CameraParameters::KEY_FACE_FILTER[] = "pantech-face-filter";
    const char CameraParameters::KEY_FACE_FILTER_ROTATION[] = "pantech-face-rotation";
    const char CameraParameters::KEY_FACE_FILTER_RECT[] = "pantech-face-filter-rect";
    const char CameraParameters::KEY_FACE_SMILE_SCORE[] = "pantech-face-smile-score";
    const char CameraParameters::KEY_FACE_SELFSHOT_NUM[] = "pantech-selfshot-num";
    const char CameraParameters::KEY_SUPPORTED_ANTISHAKE[] = "pantech-antishake-values";
    const char CameraParameters::KEY_SUPPORTED_FACE_FILTER[] = "pantech-face-filter-values";
    const char CameraParameters::LGTVT_ON[] = "on";
    const char CameraParameters::VTS_ON[] = "on";
    const char CameraParameters::VTS_OFF[] = "off";
    const char CameraParameters::KEY_VTS[] = "pantech-vts";
    const char CameraParameters::LLS_OFF[] = "pantech-lls";
    const char CameraParameters::LLS_ON[] = "on";
    const char CameraParameters::SKY_IPL_MONO_DOT[] = "pantech-ipl-mono-do";
    const char CameraParameters::SKY_IPL_FIXED_DOT[] = "pantech-ipl-fixed-dot";
    const char CameraParameters::SKY_IPL_TEXT_BB_B[] = "pantech-ipl-blackboard-b";
    const char CameraParameters::SKY_IPL_TEXT_WB_B[] = "pantech-ipl-whiteboard-b";
    const char CameraParameters::SKY_IPL_TEXT_WB_C[] = "pantech-ipl-whiteboard-c";
    const char CameraParameters::SKY_IPL_COLOR_DOT_BLACK[] = "pantech-ipl-color-dot-blk";
    const char CameraParameters::SKY_IPL_COLOR_DOT_WHITE[] = "pantech-ipl-color-dot-wh";
    \
    void CameraParameters::getColorExtractionCoordinates(int *x, int *y) const {}
    void CameraParameters::setColorExtractionCoordinates(int x, int y) {}
    void CameraParameters::getColorExtractionRGB_B(int *x, int *y) const {}
    void CameraParameters::setColorExtractionRGB_B(int x, int y) {}
    void CameraParameters::getColorExtractionRGB_G(int *x, int *y) const {}
    void CameraParameters::setColorExtractionRGB_G(int x, int y) {}
    void CameraParameters::getColorExtractionRGB_R(int *x, int *y) const {}
    void CameraParameters::setColorExtractionRGB_R(int x, int y) {}

}; // namespace android


