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

# xset dpms force off




