#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int fd = open("text.txt", O_RDWR);
	printf("%s\n",get_next_line(fd));
	return (0);
}