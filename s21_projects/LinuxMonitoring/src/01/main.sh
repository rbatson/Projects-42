#!/bin/bash

if [ $# != 1 ]
then
    echo "Wrong amount of arguments"
else
    str='^[+-]?[0-9]+([.][0-9])?$'
        if [[ $1 =~ $str ]]
    then
        echo "You can't use numbers here weirdo."
    else
        echo $1
    fi
fi