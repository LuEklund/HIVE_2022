#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

char *get_next_line(int fd);
int alloc_number(void);

int main(int argc, char **argv)
{
    char *line;
    int fd = 0;

    if (argc > 1)
    {
        fd = open(argv[1], O_RDONLY);
        if (fd < 0)
            return (0);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        write(1, line, strlen(line));
        free(line);
    }
    if (fd > 0)
        close(fd);
    if (alloc_number())
    {
        if (write(2, "MEMORY LEAK DETECTED\n", strlen("MEMORY LEAK DETECTED\n")) < 0)
        {
            write(2, "FAILED TO WRITE\n", strlen("FAILED TO WRITE\n"));
        }
        return (1);
    }
    return (0);
}