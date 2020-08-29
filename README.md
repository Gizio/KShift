# KShift

## About
<p>KShift_Auto is a KShift branch to allow for KShift to be ran with just the "Auto" command. This helps with running KShift from a menu, or at startup</p>

## Manual Installation
<p>KShift can be easily installed with <em>make</em>.</p>
<p><strong>git clone <em>https://github.com/Gizio/KShift.git</em></strong></p>
<p><strong>cd <em>[KShift directory]</em></strong></p>
<p><strong>make</strong></p>
<p><strong>make install</strong></p>
<p><strong>mkdir ~/.config/KShift</strong></p>
<p><strong>touch ~/.config/KShift/KShift.conf</strong></p>

## Automatic Instatllation
<p>KShift_Auto has an automatic script to easily compile KShift_Auto
<p><strong>git clone --single-branch --branch KShift_Auto https://github.com/Gizio/KShift.git</strong></p>
<p><strong>cd KShift</strong></p>
<p><strong>./install.sh</strong></p>

## Configuration
<p>Once KShift_Auto is installed you need to configure it to use your monitor</p>
<p>To do this first cd into the KShift config directory</p>
<p><strong>cd ~/.config/KShift/</strong></p>
<p>Then edit the .conf file</p>
<p>Type the name of your monitor on the first line (to find the name type <strong>xrandr</strong> in terminal)</p>
<p>Save the file</p>

## Uninstallation
<p><strong>cd <em>[KShift directory]</em></strong></p>
<p><strong>make uninstall</strong></p>

## Multiple Monitor Support
<p>Multiple montior support is not yet implemented, however will be in a future update</p>

## How to use
<p> For a more in-depth tutorial on how to use KShift, please type <strong>man KShift</strong> in terminal
<br>
<p> KShift </strong> <strong> [ -a ]</strong> | <strong> [ --auto ] [ -h ] </strong> | <strong> [ --help ] [ -v ] <strong> | [ --version ]
