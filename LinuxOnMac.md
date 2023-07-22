Throw
```
options hid-apple swap_fn_leftctrl=1
options hid_apple swap_opt_cmd=1
```
- in `/etc/modprobe.d/hid_apple.conf`, regenerate your initramfs w/ `mkinitcpio -p Linux`, then reboot, for a traditional keyboard experience.
<br>   

- Essential packages: `cpupower` (Set to the 'powersave' governor)  & `mbpfan`
- `Xft.dpi: 192` in `~/.Xresources` for better scaling
<br>   

- Add the following to `/etc/X11/xorg.conf.d/30-touchpad.conf`:
```
Section "InputClass"
    Identifier "touchpad"
    Driver "libinput"
    MatchIsTouchpad "on"
    Option "Tapping" "on"
    Option "NaturalScrolling" "true"
    Option "ClickMethod" "clickfinger"
    Option "AccelProfile" "flat"
    Option "TransformationMatrix" "1 0 0 0 1 0 0 0 0.3"
EndSection
```
For natural scrolling, tap-to-click and two-finger-right-click.
