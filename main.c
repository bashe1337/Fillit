#include <stdio.h>
#include "fillit.h"
#include <fcntl.h>

int main() {
	char line[546];
	int fd;
	int	i;
	int *str;
	t_fillit	*head;
	t_fillit	*tmp;

	fd = open("1",O_RDONLY);
	i = 0;

	// read(fd, line, 546);
	// printf("%d\n%s\n",validation(line),line);
	head = get_figure(line, fd, head);
	while (i < 8)
	{
	 	printf("%d", *(head->coordinate));
		head->coordinate++;
		i++;
	}
	//close(fd);
    return 0;
}
