#!/bin/bash

. printer.sh

start=`date +%s`

if [[ -n $1 ]]
then
    if [[ -d $1 ]]
    then
        if [[ ${1: -1} = "/" ]]
        then
            print_count_folders $1
            print_top_five_folders $1
            print_count_files $1
            print_conf_files $1
            print_top_ten_files $1
            print_top_ten_exec_files $1
            print_time $start
        else
            printf "Directory should end with '/'.\n"
        fi
    else
        printf "Directory not exist.\n"
    fi
else
    printf "Need one parameter to start.\n"
fi