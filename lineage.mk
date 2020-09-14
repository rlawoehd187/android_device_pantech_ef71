#
# Copyright (C) 2016 The CyanogenMod Project
#               2017 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

# Inherit some common Lineage stuff
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

# Inherit from ef71 device
$(call inherit-product, $(LOCAL_PATH)/device.mk)

PRODUCT_BRAND := SKY
PRODUCT_DEVICE := ef71
PRODUCT_NAME := lineage_ef71
PRODUCT_MODEL := IM-100
PRODUCT_MANUFACTURER := Pantech

PRODUCT_GMS_CLIENTID_BASE := android-pantech

TARGET_VENDOR_PRODUCT_NAME := ef71

PRODUCT_BUILD_PROP_OVERRIDES += \
    BUILD_FINGERPRINT="SKY/SKY_IM-100K/ef71k:6.0.1/MMB29M/IM-100K.005:user/release-keys" \
    PRIVATE_BUILD_DESC="msm8937_32-user 6.0.1 MMB29M IM-100K.005 release-keys"
