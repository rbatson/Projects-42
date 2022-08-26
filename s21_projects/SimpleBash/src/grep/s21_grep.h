#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <regex.h>
#include <string.h>
#include <getopt.h>

#define buff 999999

typedef struct {
    int e;
    int i;
    int v;
    int c;
    int l;
    int n;
    int h;
    int s;
    int f;
    int o;
    int count;
    int openCount;
} options;

void   parser(int argc, char *argv[], options *opt, char pattern[]);
void   open_file(int argc, char *argv[], options opt, char pattern[]);
void   print_line(FILE * file, char pattern[], options opt, char *nameFile);
int    find_pat(char *tmpLine, char pattern[], options* opt);
char * s21_strcat(char *dest, const char *src);

#endif  // SRC_GREP_S21_GREP_H_
