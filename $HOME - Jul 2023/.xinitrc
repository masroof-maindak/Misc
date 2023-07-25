xrdb -merge ~/.Xresources

# Let QT and GTK autodetect retina screen and autoadjust
export QT_AUTO_SCREEN_SCALE_FACTOR=1
export GDK_SCALE=2
export GDK_DPI_SCALE=0.5

# Here Xfce is kept as default
session=${1:-i3}

case $session in
    i3|i3wm           ) exec i3;;
    bsp               ) exec bspwm;;
    berry             ) exec berry;;
    *                 ) exec $1;;
esac

