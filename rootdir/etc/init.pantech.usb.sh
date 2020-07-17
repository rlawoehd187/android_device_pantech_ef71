#!/system/bin/sh
cmd="$1"
target=`getprop ro.board.platform`
target=${target:0:7}
is_ffs=0
is_cdrom=0
iso_file="/system/media/cdfree_usb.iso"
req_mode=""

initialize_oninit()
{
	# ADB MODE
	value=`getprop persist.service.adb.enable`
	if [ "$value" == "" ] ; then
		debuggable=`getprop ro.debuggable`
		if [ "$debuggable" == "1" ] ; then
			setprop persist.service.adb.enable 1
		else
			setprop persist.service.adb.enable 0
		fi
	fi
	# MDM MODE
	value=`getprop persist.pantech.usb.control`
	if [ "$value" == "" ] ; then
		setprop persist.pantech.usb.control disable
	fi
	value=`getprop persist.pantech.usb.version`
	if [ "$value" == "" ] ; then
		setprop persist.pantech.usb.version 0
	fi
	# QXDM ON/OFF
	initial_qxdm_value=`cat /sys/class/android_usb/android0/qxdm_message_onoff`
	if [ "$initial_qxdm_value" == "0" ] ; then
		setprop persist.pantech.usb.dmmask 0
	else
		setprop persist.pantech.usb.dmmask 1
	fi

	# Factory mode
	value=`getprop persist.pantech.usb.fmode`
	case "$value" in
		"")
			echo 1 > /sys/class/android_usb/android0/factory_mode
			setprop persist.pantech.usb.fmode 1
			;;
		"0")
			echo 0 > /sys/class/android_usb/android0/factory_mode
			;;
		*)
			echo 1 > /sys/class/android_usb/android0/factory_mode
			;;
	esac
	# PANTECH USB
	echo "Pantech_Incoporated" > /sys/class/android_usb/android0/iManufacturer

	value=`getprop ro.product.model` 
	case "$value" in
		"")
			echo "Android" > /sys/class/android_usb/android0/iProduct
			;;
		*)
			echo "$value" > /sys/class/android_usb/android0/iProduct
			;;
	esac

	# Should initialize because of factory_mode.
	case "$target" in
		"apq8084") #Fusion chip
			echo "diag,diag_mdm" > /sys/class/android_usb/android0/f_diag/clients
			echo "hsic" > /sys/class/android_usb/android0/f_serial/transports
			echo "serial_hsic" > /sys/class/android_usb/android0/f_serial/transport_names
			;;
		*) #one-chip
			echo "diag" > /sys/class/android_usb/android0/f_diag/clients
			echo "smd" > /sys/class/android_usb/android0/f_serial/transports
			;;
	esac
}

initialize_default_mode()
{
	echo 0 > /sys/class/android_usb/android0/enable
	if [ "$req_mode" == "mass_storage" ] ; then
		echo 10A9 > /sys/class/android_usb/android0/idVendor
		echo 1104 > /sys/class/android_usb/android0/idProduct
		echo "$req_mode" > /sys/class/android_usb/android0/functions
	else
		if [[ "$req_mode" == *rndis* ]] ; then
			echo 10A9 > /sys/class/android_usb/android0/idVendor
			echo 1104 > /sys/class/android_usb/android0/idProduct
			if [ $is_ffs == 1 ] ; then
				echo "rndis,adb" > /sys/class/android_usb/android0/functions
			else
				echo "rndis" > /sys/class/android_usb/android0/functions
			fi
		else #default mode
			echo 10A9 > /sys/class/android_usb/android0/idVendor
			echo 1105 > /sys/class/android_usb/android0/idProduct
			if [ $is_ffs == 1 ] ; then
				echo "serial,diag,adb" > /sys/class/android_usb/android0/functions
			else
				echo "serial,diag" > /sys/class/android_usb/android0/functions
			fi
		fi
	fi
	echo 1 > /sys/class/android_usb/android0/enable
}

case "$cmd" in
	"") ;; #Do nothing
	"oninit")
		initialize_oninit	
	;;
	"otg_phy_tune")
		otg_value=`getprop persist.pantech.usb.otgtune`
		case "$otg_value" in
			"")
				case "$target" in
					"apq8084" | "msm8994")
						initial_otg_value=`cat /sys/module/phy_msm_hsusb/parameters/override_otg_init`
						setprop persist.pantech.usb.otgtune $initial_otg_value
						;;
				esac
			;;
			*)
				case "$target" in
					"apq8084" | "msm8994")
						echo "$otg_value" > /sys/module/phy_msm_hsusb/parameters/override_otg_init
						;;
				esac
			;;
		esac
	;;
	"slave_phy_tune")
		phy_value=`getprop pantech.usb.phytune`
		case "$phy_value" in
			"");;
			*)
				case "$target" in
					"msm8916" | "msm8994" | "msm8937")
						echo "$phy_value" > /sys/module/phy_msm_usb/parameters/override_phy_init
						;;
					*);;
				esac
			;;
		esac
	;;	
esac

#
# Allow persistent usb charging disabling
# User needs to set usb charging disabled in persist.usb.chgdisabled
#
target=`getprop ro.board.platform`
usbchgdisabled=`getprop persist.usb.chgdisabled`
case "$usbchgdisabled" in
    "") ;; #Do nothing here
    * )
    case $target in
        "msm8660")
        echo "$usbchgdisabled" > /sys/module/pmic8058_charger/parameters/disabled
        echo "$usbchgdisabled" > /sys/module/smb137b/parameters/disabled
	;;
        "msm8960")
        echo "$usbchgdisabled" > /sys/module/pm8921_charger/parameters/disabled
	;;
    esac
esac

usbcurrentlimit=`getprop persist.usb.currentlimit`
case "$usbcurrentlimit" in
    "") ;; #Do nothing here
    * )
    case $target in
        "msm8960")
        echo "$usbcurrentlimit" > /sys/module/pm8921_charger/parameters/usb_max_current
	;;
    esac
esac

# soc_ids for 8937
if [ -f /sys/devices/soc0/soc_id ]; then
	soc_id=`cat /sys/devices/soc0/soc_id`
else
	soc_id=`cat /sys/devices/system/soc/soc0/id`
fi

# enable rps cpus on msm8937 target
setprop sys.usb.rps_mask 0
case "$soc_id" in
	"294" | "295")
		setprop sys.usb.rps_mask 10
	;;
esac
