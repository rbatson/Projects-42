#!/bin/bash

. printer.sh
. config.conf

cmp="^[1-6]$"
fontcolors=("\e[1;37" "\e[0;31m" "\e[0;32m" "\e[0;34m" "\e[0;35m" "\e[0;30m")
backgroundcolors=("\e[47m" "\e[41m" "\e[42m" "\e[44m" "\e[45m" "\e[40m")
defaultcolorfont="\e[0;31m"
defaultcolorbackground="\e[40m"
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

if ! [[ $column1_background =~ $cmp ]] \
|| ! [[ $column1_font_color =~ $cmp ]] \
|| ! [[ $column2_background =~ $cmp ]] \
|| ! [[ $column2_font_color =~ $cmp ]]
then
	if [[ $defaultcolorbackground == $defaultcolorfont ]]
       printf "\e[1;31mERROR: Font and background colors should \
not match, how are you suppose to see them?\e[0m\n"
		exit
	fi
print_data "${defaultcolorbackground}" "${defaultcolorfont}" "${defaultcolorbackground}" "${defaultcolorfont}"
printf "\n"
print_default_info
else
	if [[ $column1_background == $column1_font_color || $column2_background == $column2_font_color ]]
    then
       printf "\e[1;31mERROR: Font and background colors should \
not match, how are you suppose to see them?\e[0m\n"
		exit
	fi
print_data "${backgroundcolors[$column1_background - 1]}" "${fontcolors[$column1_font_color - 1]}" "${backgroundcolors[$column2_background - 1]}" "${fontcolors[$column2_font_color - 1]}"
printf "\n"
print_color_info
fi