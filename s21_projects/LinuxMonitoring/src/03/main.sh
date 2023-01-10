#!/bin/bash

. printer.sh

if [[ $# != 4 ]]
then
    printf "\e[1;31mERROR: Wrong amount of arguments\n\
\e[1;32mYou \e[1;33mneed \e[1;36mat \e[1;35mleast \e[1;31m4\e[0m\n"
    exit
else
    cmp="^[1-6]$"
    if ! [[ $1 =~ $cmp && $2 =~ $cmp && $3 =~ $cmp && $4 =~ $cmp ]]
    then
        printf "\e[1;31mERROR: Read manual, you can only use numbers 1 - 6\e[0m\n"
        exit
    else
        if [[ $1 == $2 || $3 == $4 ]]
        then
            printf "\e[1;31mERROR: Font and background colors should \
not match, how are you suppose to see them?\e[0m\n"
            exit
            fi
    fi
fi

fontcolors=("\e[1;37" "\e[0;31m" "\e[0;32m" "\e[0;34m" "\e[0;35m" "\e[0;30m")
backgroundcolors=("\e[47m" "\e[41m" "\e[42m" "\e[44m" "\e[45m" "\e[40m")
NoColor='\e[0m'
timedatectl set-timezone Europe/Moscow
HOSTNAME=$(hostname)
TIMEZONE="$(cat /etc/timezone) $(date -u "+%Z") $(date "+%z")"
USER=$(whoami)
OS=$(uname -mrs)
DATE=$(date +"%d %b %G %T")
UPTIME=$(uptime -p)
UPTIME_SEC=$(awk '{printf $1}' /proc/uptime)
IP=$(hostname -I)
MASK=$(ip address | grep "scope global" | grep -o "/\w*")
GATEWAY=$(ip r | grep default | awk '{printf $3}')
RAM_TOTAL=$(free -m | grep Mem | awk '{printf "%.3f GB", $2/1024}')
RAM_USED=$(free -m | grep Mem | awk '{printf "%.3f GB", $3/1024}')
RAM_FREE=$(free -m | grep Mem | awk '{printf "%.3f GB", $4/1024}')
SPACE_ROOT=$(df /root/ | awk '/\// {printf "%.2f MB", $2/1024}')
SPACE_ROOT_USED=$(df /root/ | awk '/\// {printf "%.2f MB", $3/1024}')
SPACE_ROOT_FREE=$(df /root/ | awk '/\// {printf "%.2f MB", $4/1024}')

print_data "${fontcolors[$1-1]}" "${backgroundcolors[$2-1]}" "${fontcolors[$3-1]}" "${backgroundcolors[$4-1]}"

