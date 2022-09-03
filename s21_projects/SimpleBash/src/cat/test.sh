#!/bin/bash

./s21_cat s21_cat.c >> s21_cat.txt
cat s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -b s21_cat.c >> s21_flagB.txt
cat -b s21_cat.c >> flagB.txt
diff -s s21_flagB.txt flagB.txt
rm s21_flagB.txt flagB.txt

./s21_cat -e s21_cat.c >> s21_flagE.txt
cat -e s21_cat.c >> flagE.txt
diff -s s21_flagE.txt flagE.txt
rm s21_flagE.txt flagE.txt

./s21_cat -n s21_cat.c >> s21_flagN.txt
cat -n s21_cat.c >> flagN.txt
diff -s s21_flagN.txt flagN.txt
rm s21_flagN.txt flagN.txt

./s21_cat -s s21_cat.c >> s21_flagS.txt 
cat -s s21_cat.c >> flagS.txt
diff -s s21_flagS.txt flagS.txt
rm s21_flagS.txt flagS.txt

./s21_cat -t s21_cat.c >> s21_flagT.txt
cat -t s21_cat.c >> flagT.txt
diff -s s21_flagT.txt flagT.txt
rm s21_flagT.txt flagT.txt