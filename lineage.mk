#
# Copyright (C) 2017 The LineageOS Project
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

# Inherit framework first
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

# Inherit from chaozu device
$(call inherit-product, device/pantech/ef71/device.mk)

# Inherit some common LineageOS stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

# Set those variables here to overwrite the inherited values.
BOARD_VENDOR := pantech
PRODUCT_DEVICE := ef71
PRODUCT_NAME := lineage_ef71
PRODUCT_BRAND := SKY
PRODUCT_MODEL := IM-100
PRODUCT_MANUFACTURER := pantech

# Overlays (inherit after vendor/cm to ensure we override it)
DEVICE_PACKAGE_OVERLAYS += $(LOCAL_PATH)/overlay

PRODUCT_GMS_CLIENTID_BASE := android-pantech

PRODUCT_BUILD_PROP_OVERRIDES += \
    BUILD_FINGERPRINT="SKY/SKY_IM-100K/ef71k:6.0.1/MMB29M/IM-100K.005:user/release-keys" \
    PRIVATE_BUILD_DESC="msm8937_32-user 6.0.1 MMB29M IM-100K.005 release-keys"
