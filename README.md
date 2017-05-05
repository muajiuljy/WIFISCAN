https://github.com/muajiuljy/APPDEV

# This is my readme file
Raspberry Pi acoustic sensor project

This pject will turn a raspberry Pi 3 into an acoustic sensor

1.Configurarion

1.1 Hardwave configuration

A raspberry Pi 3 is remommend.If a older version oPi is used,
corresponding configuration might be changed.
The Pi is mounted with a USB sound card,and plugged in a microphone.
It is recommonded to have Ethernet connection for your Pi.

1.2 Softwave configuration

The USB sound card has to be set as default audio device.To do so,you need
to modify two files which are asound.conf in etc folder and .asoundrc file.
 You put the following content. pcm.!default { type plug slave { pcm "hw:1,0" } } ctl.!default{ type hw card 1 }

If you are using Raspbian Jessie, you have to roll back alsa-utils to an
early version.

# WIFISCAN
