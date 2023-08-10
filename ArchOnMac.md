## Keyboard
```
options hid-apple swap_fn_leftctrl=1
options hid_apple swap_opt_cmd=1
```
in `/etc/modprobe.d/hid_apple.conf`, regenerate your initramfs w/ `mkinitcpio -p Linux`, then reboot (if skill issue, then just redownload the Linux kernel - `sudo pacman -S linux`) for a traditional keyboard experience.

## Scaling
- `Xft.dpi: 192` in `~/.Xresources`, and

```
export QT_AUTO_SCREEN_SCALE_FACTOR=1
export GDK_SCALE=2
export GDK_DPI_SCALE=0.5
```
in `~/.bash_profile`.

## Touchpad

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
For natural scrolling, tap-to-click and two-finger-right-click.

## Install
1. ```sudo pacman -S reflector broadcom-wl wmctrl pulseaudio pulseaudio-alsa alsa-utils brightness ctl networkmanager xorg-xinit ranger htop neovim firefox dunst thunar feh gthumb nitrogen maim shotgun firefox rofi polybar wezterm lxappearance-gtk3 mpv imagemagick ffmpeg zathura zathura-pdf-mupdfz upower unzip```
2. ```paru -S b43-firmware mbpfan-git cpupower-gui visual-studio-code-bin dragon-drop autotiling lutgen-git ttf-icomoon-feather-git spotify_player```.
3. Enable services for `NetworkManager` + `mbpfan`.
4. Copy rice files from dots repo.
## Other
- For internet (at least on my Macbook Pro 2014), you need the `broadcom-wl` and `b43-firmware` packages. The latter is on the AUR.
- Note: `cpupower` (Set to the 'powersave' governor (underclocks processor to lowest frequency))  & `mbpfan-git` (fan daemon) are essential for Linux on Mac.
- Also check out [scripts](Scripts/) and move the contents to your `.local/bin` (or any other directory in your path).
