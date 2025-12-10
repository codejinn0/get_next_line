#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main ()
{
    int fd1 =open("file1.txt",O_RDONLY);
    // int fd2 =open("file2.txt",O_RDONLY);  

    char *str1 = get_next_line(fd1);
    while(str1){
        printf("%s",str1);
        free(str1);
        str1 = get_next_line(fd1);
    }
//     char *str2= get_next_line(fd2);
//     while(str2){
//         printf("%s",str2);
//         free(str2);
//         str2 = get_next_line(fd2);
//     }
    close(fd1);
//     close(fd2);
}
