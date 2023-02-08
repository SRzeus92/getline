#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int 	fd = open("file.txt", O_RDONLY);
	char	*str = get_next_line(fd);

	while (str)
	{
		printf("%s$\n", str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
}
