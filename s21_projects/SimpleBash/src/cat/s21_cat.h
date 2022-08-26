#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>

typedef struct options_s {
    int b;
    int e;
    int n;
    int s;
    int t;
    int v;
}opt;


static struct option long_options[] = {
    {"--number", 0, 0, 'n'},
    {"--squeeze-blank", 0, 0, 's'},
    {"--number-nonblank", 0, 0, 'b'},
    {0, 0, 0, 0}
};

void parser(int argc, char **argv, opt *options);
void reader(char **argv, opt *options);


#endif  // SRC_CAT_S21_CAT_H_
