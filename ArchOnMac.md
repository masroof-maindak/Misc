- Throw
```
options hid-apple swap_fn_leftctrl=1
options hid_apple swap_opt_cmd=1
```
in `/etc/modprobe.d/hid_apple.conf`, regenerate your initramfs w/ `mkinitcpio -p Linux`, then reboot (if skill issue, then just redownload the Linux kernel - `sudo pacman -S linux` on Arch), for a traditional keyboard experience.
<br>   

- Essential packages: `cpupower` (Set to the 'powersave' governor (underclocks processor to lowest frequency))  & `mbpfan`. <br>

- `Xft.dpi: 192` in `~/.Xresources` for better scaling. <br>

- Add
```
export QT_AUTO_SCREEN_SCALE_FACTOR=1
export GDK_SCALE=2
export GDK_DPI_SCALE=0.5
```
to `~/.bash_profile` for the same in GTK/QT apps.

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
    Option "DisableWhileTyping" "0"
    Option "TransformationMatrix" "1 0 0 0 1 0 0 0 0.3"
EndSection
```
For natural scrolling, tap-to-click and two-finger-right-click. <br>
- For internet (at least on my Macbook Pro 2014), you need the `broadcom-wl` and `b43-firmware` packages. The latter is on the AUR. <br>