// Copyright [2022] <rbatson>
#include "./s21_grep.h"

int main(int argc, char **argv) {
    char pattern[1024] = {0};
    options opt = {0};
    parser(argc, argv, &opt, pattern);
    open_file(argc, argv, opt, pattern);
    return 0;
}

void parser(int argc, char **argv, options *opt, char *pattern) {
    int c = 0;
    int index = 0;
    char tmp_line[buff] = {0};
    while ((c = getopt_long(argc, argv, "e:ivclnshof:", 0 , &index)) != -1) {
        switch (c) {
            case 'e':
                opt->e = 1;
                s21_strcat(pattern, optarg);
                s21_strcat(pattern, "|");
                break;
            case 'i':
                opt->i = 1;
                break;
            case 'v':
                opt->v = 1;
                break;
            case 'c':
                opt->c = 1;
                break;
            case 'l':
                opt->l = 1;
                break;
            case 'n':
                opt->n = 1;
                break;
            case 's':
                opt->s = 1;
                break;
            case 'h':
                opt->h = 1;
                break;
            case 'f':
                opt->f = 1;
                FILE *file = fopen(argv[optind-1], "r");
                if (file) {
                    fgets(tmp_line, buff, file);
                    s21_strcat(pattern, tmp_line);
                    fclose(file);
                }
                break;
            case 'o':
                opt->o = 1;
                break;
            default:
            break;
        }
    }
    if (argv[optind]) {
        if (opt->e && !opt->f)
            pattern[strlen(pattern)-1] = '\0';
        if (strlen(pattern) == 0)
            s21_strcat(pattern, argv[optind]);
        for (int i = optind; i < argc; i++) {
            FILE *file = fopen(argv[i], "r");
            if (file) {
                opt->openCount++;
                fclose(file);
            }
        }
    }
}

void open_file(int argc, char **argv, options opt, char *pattern) {
    FILE * file = NULL;
    for (int i = optind; i < argc; i++) {
        file = fopen(argv[i], "r");
        if (file) {
            char *nameFile = (opt.openCount > 1) ? argv[i] : NULL;
            if (opt.l)
                nameFile = argv[i];
            print_line(file, pattern, opt, nameFile);
            fclose(file);
        } else if (!opt.s && argv[i][0] != '-') {
            if (opt.e) {
                printf("s21_grep: %s: No such file or directory\n", argv[i]);
            } else if (argv[optind] != argv[i]) {
                printf("s21_grep: %s: No such file or directory\n", argv[i]);
            }
        }
    }
}

int find_pat(char *tmpLine, char *pattern, options *opt) {
    regex_t regex;
    int success = 0;
    int res = 0;
    int regFlag = (opt->i) ? REG_ICASE | REG_EXTENDED : REG_EXTENDED;

    regcomp(&regex, pattern, regFlag);
    if (opt->v)
        res = REG_NOMATCH;
    success = regexec(&regex, tmpLine, 0, NULL, 0);
    regfree(&regex);
    return (success == res) ? 0 : 1;
}

void print_line(FILE *file, char *pattern, options opt, char *nameFile) {
    char tmp_line[buff] = {0};
    int ext = 1;
    int lineCount = 0;
    while (ext) {
        lineCount++;
        char *line = fgets(tmp_line, buff, file);
        int success = find_pat(tmp_line, pattern, &opt);
        if (line == NULL) {
            ext = 0;
        } else if (success == 0) {
            opt.count++;
            if (!opt.c && !opt.l) {
                if (nameFile && !opt.h)
                    printf("%s:", nameFile);
                if (opt.n)
                    printf("%d:", lineCount);
                if (opt.o)
                    printf("%s\n", pattern);
                if (!opt.o)
                     printf("%s", tmp_line);
                if (feof(file) && tmp_line[strlen(tmp_line)-1] != '\n')
                    printf("\n");
            }
            if (opt.l) {
                printf("%s\n", nameFile);
                ext = 0;
            }
        }
    }
    if (opt.c && nameFile)
        printf("%s:", nameFile);
    if (opt.c)
        printf("%d\n", opt.count);
}

char * s21_strcat(char *dest, const char *src) {
    char *flag;
    char *start = dest;
    while (*start != '\0') {
        start++;
    }
    while (*src != '\0') {
        *start++ = *src++;
    }
    *start = '\0';
    flag = dest;
    return flag;
}
