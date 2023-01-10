#!/bin/bash

function print_count_folders {
    printf "Total number of folders (including all nested ones) = $(find $1 -type d| wc -l)\n"
}

function print_top_five_folders {
    printf "TOP 5 folders of maximum size arranged in descending order (path and size):\n"
    du -h $1 2>/dev/null | sort -hr | head -5 | awk 'BEGIN{i=1}{printf "%d - %s, %s\n", i, $2, $1; i++}'
}

function print_count_files {
    printf "Total number of files = $(ls -laR $1 2>/dev/null | grep ^- | wc -l)\n"
}

function print_conf_files {
  printf "Number of:\n"
  printf "Configuration files (with the .conf extension) = $(find $1 2>/dev/null -type f -name "*.conf" | wc -l | awk '{print $1}')\n"
  printf "Text files = $(find $1 2>/dev/null -type f -name "*.txt" | wc -l | awk '{print $1}')\n"
  printf "Executable files = $(find $1 2>/dev/null -type f -executable | wc -l | awk '{print $1}')\n"
  printf "Log files (with the extension .log) = $(find $1 2>/dev/null -type f -name "*.log" | wc -l | awk '{print $1}')\n"
  printf "Archive files = $(find $1 2>/dev/null -type f -name "*.zip" -o -name "*.7z" -o -name "*.rar" -o -name "*.tar" | wc -l | awk '{print $1}')\n"
  printf "Symbolic links = $(find $1 2>/dev/null -type l | wc -l | awk '{print $1}')\n"
}

function print_top_ten_files {
  printf "TOP 10 files of maximum size arranged in descending order (path, size and type):\n"
  for num in {1..10}
  do
      file_line=$(find $1 2>/dev/null -type f -exec du -h {} + | sort -rh | head -10 | sed "${num}q;d")
      if ! [[ -z $file_line ]]
      then
          printf "$num - "
          printf "$(echo $file_line | awk '{print $2}'), "
          printf "$(echo $file_line | awk '{print $1}'), "
          printf "$(echo $file_line | grep -m 1 -o -E "\.[^/.]+$" | awk -F . '{print $2}')\n"
      fi
  done
}

function print_top_ten_exec_files {
  printf "TOP 10 executable files of the maximum size arranged in descending order (path, size and MD5 hash of file):\n"
  for num in {1..10}
  do
      file_line=$(find $1 2>/dev/null -type f -executable -exec du -h {} + | sort -rh | head -10 | sed "${num}q;d")
      if ! [[ -z $file_line ]]
      then
          printf "$num - "
          printf "$(echo $file_line | awk '{print $2}'), "
          printf "$(echo $file_line | awk '{print $1}'), "
          
          path=$(echo $file_line | awk '{print $2}')
          MD5=$(md5sum $path | awk '{print $1}')
          printf "$MD5\n"
      fi
  done
}

function print_time {
  end=`date +%s`
  printf "Script execution time (in seconds) = $(($end-$1))\n"
}
