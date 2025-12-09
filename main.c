// #include <fcntl.h>
// #include <stdio.h>
// #include "get_next_line.h"

// int main()
// {
//     int     fd1;
//     int     fd2;
//     char   *str1;
//     char    *str2;

    

//     fd1 = open("file1.txt", O_RDONLY);
//     fd2 = open("file2.txt", O_RDONLY);
   
//     str1 = get_next_line(fd1);
//     str2 = get_next_line(fd2);

//      while (str1 != NULL)
//      {
//         printf("%s", str1);
//         free(str1);  
//          get_next_line(fd1);
//      }
//          while (str2 != NULL)
//     {
//         printf("%s", str2);
//         free(str2); 
//         get_next_line(fd2);
//     }
//     close(fd1);
//     close(fd2);
//     return (0);
// }
