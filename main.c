#include <stdio.h>
#include "fillit.h"
#include <fcntl.h>

//invalid_width_broad
//invalid_width_short
// asdf/
int main()
{
	int i = 0;
	//char *temp;
	char line[700];
	int fd;
	//char *name;
	//int ret;
	int k = 0;
	t_fillit *head;
/*	if (ac == 2)
	{
		name = av[1];
		fd = open(name,O_RDONLY);
		ret = read(fd, line, 700);
		line[ret] = '\0';
		if (validation(line) == 0)
			ft_putstr("error");
		else
			ft_putstr("ok");
	}*/
	// i = 1;
	// temp = "examples/";
	// name = ft_strjoin(temp,av[1]);

	// while(name) {
	// 	if ((ft_strcmp(name,"examples/ok_02") == 0))
	// 		k = 0;
	// 	fd = open(name, O_RDONLY);
	// 	ret = read(fd, line, 700);
	// 	line[ret] = '\0';
	// 	if (validation(line) == 1)
	// 		printf("__________________________\n%     s\n****\n*%s*\n****\n\n%s__________________________", name, "OK",line);
	// 	else
	// 		printf("__________________________\n%     s\n*******\n*%s*\n*******\n\n%s__________________________", name, "ERROR",line);
	// 	close(fd);
	// 	i++;
	// 	free(name);
	// 	name = ft_strjoin(temp,av[i]);
	// }
	fd = open("1", O_RDONLY);
	head= NULL;
	head = read_figure(line, fd, head);
	while (head != NULL)
	{
		i = 0;
		while (i < 4)
		{
			k = 0;
			while (k < 4)
				printf("%c", head->coordinate[i][k++]);
			printf("\n");
			i++;
		}
		head = head->next;
	}
    return 0;
}
