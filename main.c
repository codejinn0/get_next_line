#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
    int     fd;
    char    *str;

    fd = open("file1.txt", O_RDONLY);
    // if (fd == -1)
    // {
    //     printf("Error opening file\n");
    //     return (1);
    // }
    str = get_next_line(fd);
    // while (str != NULL)
    // {
    //     printf("%s", str);
    //     free(str);
    //     str = get_next_line(fd);
    // }
     printf("%s", str);
     free(str);
    close(fd);
    return (0);
}
