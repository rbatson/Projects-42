#include "./s21_grep.h"

void parser(int argc, char *argv[], options *opt, char pattern[]) {
    int c = 0;
    int index = 0;
    char tmp_line[buff] = {0};
    while ((c = getopt_long(argc, argv, "e:ivclnshof", 0, &index)) != -1) {
        switch(c) {
            case 'e':
                opt->e = 1;
                s21_strcat(pattern, optarg);
                s21_strcat(pattern, "|");
                break;
            case 'i':
                opt-> i
        }
    }
}