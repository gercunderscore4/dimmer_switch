# https://github.com/raspberrypi/firmware/issues/420
# Change HDMI CEC name
# cec_osd_name=MyRPi1
# hdmi_ignore_cec_init=1  # to hide it
# in /boot/config.txt (or on newer, /boot/firmware/config.txt)
#
# https://pimylifeup.com/raspberrypi-hdmi-cec/
#
# ensure that HDMI is the sound source
# sudo raspi-config
#
# set up utils
# sudo apt update
# sudo apt upgrade
# sudo apt install cec-utils
#
# echo 'scan' | cec-client -s -d 1
# home:
# device #0 TV device 0.0.0.0 Sony TV, CEC v 1.4
# device #1 recorder 3.0.0.0 (RPi)
# device #4 playback 1.0.0.0
#
# power
# echo 'on 0.0.0.0' | cec-client -s -d 1
# echo 'standby 0.0.0.0' | cec-client -s -d 1
#
# power status
# echo 'pow 0.0.0.0' | cec-client -s -d 1
#
# help
# echo 'h 0.0.0.0' | cec-client -s -d 1
#
# set name
# echo 'osd 3.0.0.0 Satellite' | cec-client -s -d 1
# not working
#
# volume
# echo 'volup' | cec-client -s -d 1
# echo 'voldown' | cec-client -s -d 1
# echo -e 'volup\nvolup\nvolup\nvolup\nvolup\nquit' | cec-client -d 1
# need to remove -s for multiple commands, and end with quit
#
# is a device on
# echo 'ad 1' | cec-client -s -d 1
#
# is a device on
# echo 'sp 1' | cec-client -s -d 1
# Only the TV is allowed to send CEC_OPCODE_SET_STREAM_PATH
# 
# switch to me
# echo 'as' | cec-client -s -d 1
#
# cvlc --play-and-exit --fullscreen --no-video-title-show --mouse-hide-timeout 0 --video-on-top file:///home/gcard/github_repos/dimmer_switch/vhs/blarg.mkv
# ctrl+q to quit
#
# xset dpms force off
# or
# xset -display :0 s blank
# xset -display :0 dpms force off
# xset -display :0 dpms force on
# or
# sleep 1; xset s activate


sleep 1
xset s activate
for file in ./*.mkv; do
    [ -e "$file" ] || continue
    # need to sleep for 3600
    sleep 10
    vidpath=$(realpath "$file")
    echo 'as' | cec-client -s -d 1
    cvlc --play-and-exit --fullscreen --no-video-title-show --mouse-hide-timeout 0 --video-on-top "file://$vidpath"
    #need instanty darkness
    xset s activate
done

