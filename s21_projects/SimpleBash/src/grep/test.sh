#!/bin/bash

./s21_grep e s21_grep.c Makefile > s21_10.txt  # 10 
grep e s21_grep.c Makefile > 10.txt
diff -s s21_10.txt 10.txt
rm s21_10.txt 10.txt

./s21_grep -i e s21_grep.c > s21_11.txt  # 11 i
grep -i e s21_grep.c > 11.txt
diff -s s21_11.txt 11.txt
rm s21_11.txt 11.txt

./s21_grep -v e s21_grep.c > s21_12.txt  # 12 v
grep -v e s21_grep.c > 12.txt
diff -s s21_12.txt 12.txt
rm s21_12.txt 12.txt

./s21_grep -c e s21_grep.c > s21_13.txt  # 13 c
grep -c e s21_grep.c > 13.txt
diff -s s21_13.txt 13.txt
rm s21_13.txt 13.txt

./s21_grep -l e s21_grep.c s21_grep.h Makefile  > s21_14.txt  # 14 l
grep -l e s21_grep.c s21_grep.h Makefile  > 14.txt
diff -s s21_14.txt 14.txt
rm s21_14.txt 14.txt

./s21_grep -n e s21_grep.h  > s21_15.txt  # 15 n
grep -n e s21_grep.h  > 15.txt
diff -s s21_15.txt 15.txt
rm s21_15.txt 15.txt

./s21_grep -o grep s21_grep.c  > s21_16.txt  # 16 o
grep -o grep s21_grep.c  > 16.txt
diff -s s21_16.txt 16.txt
rm s21_16.txt 16.txt

./s21_grep -h grep s21_grep.c Makefile > s21_17.txt  # 17 h
grep -h grep s21_grep.c Makefile > 17.txt
diff -s s21_17.txt 17.txt
rm s21_17.txt 17.txt

./s21_grep grep -s 123123 > s21_18.txt  # 18 s
grep grep -s 123123 > 18.txt
diff -s s21_18.txt 18.txt
rm s21_18.txt 18.txt

./s21_grep -f pattern s21_grep.c > s21_19.txt  # 19 f
grep -f pattern s21_grep.c > 19.txt
diff -s s21_19.txt 19.txt
rm s21_19.txt 19.txt

./s21_grep -in grep s21_grep.c > s21_20.txt  # 20 in
grep -in grep s21_grep.c > 20.txt
diff -s s21_20.txt 20.txt
rm s21_20.txt 20.txt

./s21_grep -cv e s21_grep.c > s21_21.txt  # 21 cv
grep -cv e s21_grep.c > 21.txt
diff -s s21_21.txt 21.txt
rm s21_21.txt 21.txt

./s21_grep -iv e s21_grep.c > s21_22.txt  # 22 iv
grep -iv e s21_grep.c > 22.txt
diff -s s21_22.txt 22.txt
rm s21_22.txt 22.txt

./s21_grep -lv e s21_grep.c Makefile s21_grep.h > s21_23.txt  # 23 lv
grep -lv e s21_grep.c Makefile s21_grep.h > 23.txt
diff -s s21_23.txt 23.txt
rm s21_23.txt 23.txt

./s21_grep -ho s21 s21_grep.c s21_grep.h > s21_24.txt  # 24 ho
grep -ho s21 s21_grep.c s21_grep.h > 24.txt
diff -s s21_24.txt 24.txt
rm s21_24.txt 24.txt

./s21_grep -nf pattern s21_grep.c > s21_25.txt  # 25 nf
grep -nf pattern s21_grep.c > 25.txt
diff -s s21_25.txt 25.txt
rm s21_25.txt 25.txt
