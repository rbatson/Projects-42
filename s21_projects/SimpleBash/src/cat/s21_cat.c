#include "./s21_cat.h"

void parser(int argc, char **argv, opt *options) {
    int opt;
    int option_index = 0;
    while ((opt = getopt_long(argc, argv, "+bEnsTvet", long_options, &option_index)) != -1) {
        if (opt == 'e') {
            options->e = 1;
            options->v = 1;
        } else if (opt == 't') {
            options->t = 1;
            options->v = 1;
        } else if (opt == 'b') {
            options->b = 1;
        } else if (opt == 'n') {
            options->n = 1;
        } else if (opt == 's') {
            options->s = 1;
        } else if (opt == 'v') {
            options->v = 1;
        } else if (opt == 'T') {
            options->t = 1;
        } else if (opt == 'E') {
            options->e = 1;
        } else {
            fprintf(stderr, "use benstvTE");
            exit(1);
        }
    }
}

void reader(char **argv, opt *options) {
    FILE *fp;
    fp = fopen(argv[optind], "r");
    if (fp) {
        int str_count = 1;
        int empty_str = 0;
        int last_sym = '\n';
        while (1) {
            int cur = fgetc(fp);
            if (cur == EOF)
                break;
            if (options->s && cur == '\n' && last_sym == '\n') {
                empty_str++;
                if (empty_str > 1)
                    continue;
            } else {
                empty_str = 0;
            }
            if (last_sym == '\n' && ((options->b && cur != '\n') || options->n))
                printf("%6d\t", str_count++);
            if (options->e == 1 && cur == '\n')
                printf("$");
            if (options->t && cur == '\t') {
                printf("^");
                cur = 'I';
            }
            if (options->v) {
                if ((cur >= 0 && cur < 9) || (cur > 10 && cur < 32)) {
                    printf("^");
                    cur += 64;
                }
            }
        printf("%c", cur);
        last_sym = cur;
        }
    fclose(fp);
    } else {
        printf("No such file");
        exit(1);
    }
}

int main(int argc, char **argv) {
    opt options = {0};

    if (argc < 2) {
        printf("Неверное колличество аргументов");
        exit(1);
    }
    parser(argc, argv, &options);
    if (options.b)
        options.n = 0;
    if (options.v) {
        options.t = 0;
        options.e = 0;
    }
    reader(argv, &options);
    return (0);
}
