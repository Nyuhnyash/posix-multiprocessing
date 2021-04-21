#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <ctype.h>

#include "../core.h"

#define X 'x'
#define Y 'y'

void create_fifo(const char *path)
{

    if (!access(path, F_OK))
        remove(path);
    if (mkfifo(path, S_IFIFO | 0666))
        err("Failed to create fifo");
    
    puts("FIFO создано");
}

void print_unchanged(const char *fifopath)
{
    FILE *fifo = fopen(fifopath, "w");

    char buf[256];
    while (fgets(buf, sizeof(buf), stdin) != NULL)
            fprintf(isdigit(buf[0]) ? stdout : fifo, "%s", buf);

    fclose(fifo);
}

int print_swapped_XY(const char *fifopath, int *lengths /* zero-filled array */)
{
    FILE *fifo = fopen(fifopath, "r");
    
    char c;
    int line_num = 0;

    while ((c = (char)fgetc(fifo)) != EOF)
    {
        if (c == '\n')
        {
            line_num++;
            puts("");
        }
        else
        {
            printf("%c", tolower(c) == X ? Y : c == Y ? X : c);
            lengths[line_num]++;
        }
    }

    puts("");
    fclose(fifo);
    return line_num + 1;
}
