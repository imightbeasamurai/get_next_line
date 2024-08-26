#include "get_next_line.h"

int main(int ac, char **av)
{
    if (ac >= 2)
    {
        int fileD;
        char *line;
        fileD = open(av[1], O_RDONLY);
        line = get_next_line(fileD);

        printf("line 1 :%s", line);
        line = get_next_line(fileD);
        printf("line 2 :%s", line);
        line = get_next_line(fileD);
        printf("line 3 :%s", line);
    }
    else
    {
        printf("Not enough arguments!");
    }
}