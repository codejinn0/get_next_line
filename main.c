#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
    int     fd1;
    int     fd2;
    

    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);
   
    printf("%s",get_next_line(fd1));
    printf("%s",get_next_line(fd2));

    // while (str != NULL)
    // {
    //     printf("%s", str);
    //     free(str);  // Free each line after use
    //     str = get_next_line(fd);
    // }
    close(fd1);
    close(fd2);
    return (0);
}
