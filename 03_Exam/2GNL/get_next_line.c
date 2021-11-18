#include <stdlib.h>
#include <unistd.h>

int get_next_line(int fd, char **line)
{
	*line = malloc(10000);
	char ch;
	int res;
	int i = 0;

	while ((res = read(fd, &ch, 1)) > 0 && ch != '\n')
		line[0][i++] = ch;
	line[0][i] = '\0';
	return (res);
}