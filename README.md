# get_next_line

*This project has been created as part of the 42 curriculum by aantari.*

## Description

The **get_next_line** project is a function that reads a line from a file descriptor. The goal is to implement a function that returns a line ending with a newline character when reading from a file descriptor, one line at a time. This project teaches about static variables, dynamic memory allocation, file manipulation, and buffer management in C.

The function prototype is:
```c
char *get_next_line(int fd);
```

The function reads from the given file descriptor and returns the next line (including the `\n` character if present), or `NULL` when the end of file is reached or an error occurs.

## Instructions

### Compilation

The project must be compiled with the following flags:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

You can modify the `BUFFER_SIZE` value during compilation:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 get_next_line.c get_next_line_utils.c
```

### Testing

Create a test file (e.g., `main.c`):
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    
    close(fd);
    return (0);
}
```

Compile and run:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
./a.out
```

### Memory Leak Testing

Test with Valgrind to ensure no memory leaks:
```bash
valgrind --leak-check=full --show-leak-kinds=all ./a.out
```

## Algorithm Explanation

### Selected Algorithm: Static Variable Buffer Management

The implementation uses a **static variable** to preserve data between function calls. This is essential because `get_next_line` must maintain state across multiple invocations to correctly handle cases where a single `read()` call retrieves multiple lines or partial lines.

#### Algorithm Overview:

1. **Static Buffer (`rest`)**: A static pointer stores leftover data from previous reads that didn't form a complete line.

2. **Read Loop**: 
   - Allocate a temporary buffer of size `BUFFER_SIZE`
   - Read from the file descriptor into this buffer
   - Append the read data to `rest` using string concatenation
   - Continue until a newline character is found or EOF is reached

3. **Line Extraction**:
   - Search for the first `\n` character in `rest`
   - Extract everything up to and including the `\n` as the return line
   - Update `rest` to contain only the remaining data after the `\n`

4. **Edge Cases**:
   - If no newline is found and EOF is reached, return the remaining content
   - If `rest` is empty after extraction, free it and set to NULL
   - Handle read errors by freeing resources and returning NULL


## Resources

### Documentation
- [Linux man pages - read(2)](https://man7.org/linux/man-pages/man2/read.2.html)
- [C Static Variables](https://www.geeksforgeeks.org/static-variables-in-c/)
- [Dynamic Memory Allocation in C](https://www.cprogramming.com/tutorial/c/lesson6.html)

### Tutorials
- [42 Docs - get_next_line](https://harm-smits.github.io/42docs/projects/get_next_line)
- [File I/O in C Programming](https://www.programiz.com/c-programming/c-file-input-output)

### AI Usage
AI (Claude) was used as a learning assistant to help understand key concepts needed for this project:

**Understanding Static Variables**: AI helped explain how static variables work in C, how they persist between function calls, and why they are essential for maintaining state in `get_next_line`.

