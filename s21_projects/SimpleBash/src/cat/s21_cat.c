// Copyright [2022] <rbatson>
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

typedef struct {
    int b;
    int e;
    int s;
    int t;
    int n;
    int v;
} options;

void parser(int argc, char *argv[], options * opt);
void print_file(FILE *file, options opt);
void open_file(int argc, char *argv[], options opt);

int main(int argc, char * argv[]) {
    options opt = {0};
    parser(argc, argv, &opt);
    open_file(argc, argv, opt);

    return 0;
}

void parser(int argc, char* argv[], options * opt) {
    int c = 0;
    int index = 0;
    static struct option options[] = {
        {"number-nonblank", 0, 0, 'b'},
        {"number", 0, 0, 'n'},
        {"squeeze-blank", 0, 0, 's'},
        {0, 0, 0, 0},
    };
    while ((c = getopt_long(argc, argv, "bestnETv", options, &index)) != -1) {
        switch (c) {
        case 'b':
            opt->b = 1;
            break;
        case 'e':
            opt->e = 1;
            break;
        case 's':
            opt->s = 1;
            break;
        case 't':
            opt->t = 1;
            break;
        case 'n':
            opt->n = 1;
            break;
        case 'E':
            opt->e = 1;
            opt->v = 1;
            break;
        case 'T':
            opt->t = 1;
            opt->v = 1;
            break;
        case 'v':
            opt->v = 1;
            break;
        default:
            break;
        }
    }
}

void open_file(int argc, char *argv[], options opt) {
    for (int i = optind; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        if (file) {
            print_file(file, opt);
        }
    }
}

void print_file(FILE *file, options opt) {
    int sFlag = 1;
    int prev_ch = '\n';
    int emptyLine = 0;
    int lineCount = 1;
    int ext = 1;
    while (ext) {
        int ch = getc(file);
        if (ch == EOF) {
            ext = 0;
        } else {
            if (opt.s && ch == '\n' &&  // s
            prev_ch == '\n') {
                emptyLine++;
                if (emptyLine > 1) {
                    sFlag = 0;
                }
            } else {
                sFlag = 1;
                emptyLine = 0;
            }
            if (sFlag) {
                if (((ch != '\n' && opt.b) ||
                (opt.n && !opt.b)) && prev_ch == '\n') {  // b & n
                    printf("%6d\t", lineCount);
                    lineCount++;
                }
                if ((opt.t) && ch == '\t') {  // t & T
                    printf("^");
                    ch = 'I';
                }
                if ((opt.v && ch >= 0 && ch < 32) &&
                (ch != 9 && ch != 10)) ch += 64;  // v
                if ((opt.e) && ch == '\n') printf("$");  // e & E
                printf("%c", ch);
                prev_ch = ch;
            }
        }
    }
}
