#include "get_next_line.h"

int main()
{
    int fileD;
	char	*line;
    
    fileD = open("text2.txt", O_RDONLY);
	line = get_next_line(fileD);
    printf("line 1 :%s", line);
	line = get_next_line(fileD);
    printf("line 2 :%s", line);
	line = get_next_line(fileD);
    printf("line 3 :%s", line);

}