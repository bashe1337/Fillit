#include <stdio.h>
#include "fillit.h"
#include <fcntl.h>

int main() {
	char line[546];
	int fd;

	fd = open("1",O_RDONLY);

	// read(fd, line, 546);
	// printf("%d\n%s\n",validation(line),line);
	get_figure(line, fd);

	//close(fd);
    return 0;
}
