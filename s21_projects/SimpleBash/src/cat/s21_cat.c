#include "s21_cat_header.h"

typedef struct options_t
{
    int b;
    int e;
    int n;
    int s;
    int t;
    int v;
}opt;


static struct option long_options[] =
{
    {"--number", 0, 0, 'n'},
    {"--squeeze-blank", 0, 0, 's'},
    {"--number-nonblank", 0, 0, 'b'},
    {0, 0, 0, 0}
};

void parser(int argc, char **argv, opt *options)
{
    int opt;
    int option_index;
    while ((opt = getopt_long(argc, argv, "+benstvTE", long_options, &option_index)) != -1)
    {
        if (opt == 'e')
        {
            options->e = 1;
            options->v = 1;
        }
        else if (opt == 't')
        {
            options->t = 1;
            options->v = 1;
        }
        else if (opt == 'b')
            options->b = 1;
        else if (opt == 'n')
            options->n = 1;
        else if (opt == 's')
            options->s = 1;
        else  if (opt == 'v')
            options->v = 1;
        else if (opt == 'T')
            options->t = 1;
        else if (opt == 'E')
            options->e = 1;
        else
        {
            fprintf(stderr, "use benstvTE");
            exit(1);
        }
    }
}

void reader(char **argv, opt *options)
{
    FILE *fp;
    fp = fopen(argv[optind], "r");
    if (fp)
    {
        int cur = 0;
        int counter = 0;
        int str_count = 0;
        while ((cur = fgetc(fp)) != EOF)
        {
            if (options->b == 1)
            {
                if (cur != '\n')
                {
                    if (counter == 0)
                    {
                        printf("%6d\t", ++str_count);
                        counter = 1;
                    }
                }
                else
                    counter = 0;
            }
            if (options->n == 1)
            {
                if (cur != '\n')
                {
                    
                }
                else
                    counter = 0;
            }
        printf("%c", cur);
        }
    }
    else
        printf("No such file");
}

int main(int argc, char **argv)
{
    opt options = {0};

    if (argc < 2)
    {
        printf("Неверное колличество аргументов");
        exit(1);
    }

    parser(argc, argv, &options);
    if (options.b)
        options.n = 0;
    reader(argv, &options);

    return (0);
}
