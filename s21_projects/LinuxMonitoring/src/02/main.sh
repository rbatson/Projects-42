#!/bin/bash

. printer.sh

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

print_data
ask_to_save