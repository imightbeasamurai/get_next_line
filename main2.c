#include "get_next_line.h"

int main(int ac, char **av)
{
    int filedesciptor;
    char *line;

    filedesciptor = open (av[1], O_RDONLY);
    if (ac == 2)
    {
    line =get_next_line (filedesciptor);
    printf("line 1 :%s\n", line);
    line =get_next_line (filedesciptor);
    printf("line 2 :%s\n", line);
    line =get_next_line (filedesciptor);
    printf("line 3 :%s\n", line);
    line =get_next_line (filedesciptor);
    printf("line 4 :%s\n", line);
    }
}