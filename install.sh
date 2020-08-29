#!/bin/sh

if [ "$EUID" -eq 0 ]; then
	echo "DO NOT RUN THIS FILE AS ROOT: doing so may harm your system"
	>&2 echo "Fatal: E0: File ran as root"
	exit
fi

if [ ! -d "$HOME/.config" ]; then
	>&2 echo "E1: Directory "~/.config" not found, creating one"
	mkdir ~/.config
fi

echo "Atempting to create ~/.config/KShift"
mkdir $HOME/.config/KShift
if [ -d $HOME/.config/KShift ]; then 
	echo "Succesfully created ~/.config/KShift"
else
	>&2 echo "Fatal: E1: Directory "~/.config/KShift" not found, please create one"
fi

echo "Attempting to create ~.config/KShift/KShift.conf"

touch $HOME/.config/KShift/KShift.conf

if [ -e $HOME/.config/KShift/KShift.conf ]; then
	echo "Succesfully created ~/.config/KShift/KShift.conf"
else 
	echo "Fatal: E2: File "~/.config/KShift" not found, please create one"
fi

if [ -e /usr/bin/xrandr ];  then
	>&2 echo "E2: File "/usr/bin/xrandr" not found, if xrandr is installed, disregard this error"
fi
echo "Building KShift..."
make
echo "Installing KShift..."
if [ -e /usr/bin/sudo ]; then
	sudo make install 
elif [ -e /usr/bin/doas ]; then
	echo "E2: File "/usr/bin/sudo" not found, attempting to use doas instead"
	doas make install
else
	echo "E2: File "/usr/bin/sudo" not found"
	echo "E2: File "/user/bin/doas" not found"
	echo "Cannot escalate priveleges"
	exit
fi
echo "Finished"
