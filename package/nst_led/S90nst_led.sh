#! /bin/sh

#
# nst led
#

date

#if [ ! -c "/dev/ledrgb" ];then
#    mknod "/dev/ledrgb" c 244 1
#fi

case "$1" in
    start)
    printf "Starting nst led: "
    /usr/bin/nst_led --num=6 --times=1 --speed=300 --time=0 --style="$2" --mute_led=1 --listen_led=1
    [ $? = 0 ] && echo "OK" || echo "FAIL"
    ;;
    stop)
    printf "Stopping nst led: "
    /usr/bin/nst_led --num=6 --times=0 --speed=300 --time=0 --style=2 --mute_led=1 --listen_led=1
    [ $? = 0 ] && echo "OK" || echo "FAIL"	
    ;;
    *)
    echo "Usage: $0 {start num{0~30}|stop}"
    exit 1
    ;;
esac
