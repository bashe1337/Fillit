/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bashe <bashe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:23:27 by bashe             #+#    #+#             */
/*   Updated: 2019/11/25 21:00:45 by bashe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fillit	*create(void)
{
	t_fillit	*new_elem;
	int			y;
	int			x;

	y = 0;
	new_elem = (t_fillit *)ft_memalloc(sizeof(t_fillit));
	new_elem->coordinate = (char **)ft_memalloc(sizeof(char *) * 4);
	while (y < 4)
	{
		x = 0;
		new_elem->coordinate[y] = (char *)ft_memalloc(sizeof(char) * 4);
		while (x < 4)
			new_elem->coordinate[y][x++] = '.';
		y++;
	}
	new_elem->next = NULL;
	return (new_elem);
}

t_fillit	*new_node(t_fillit *head)
{
	t_fillit	*tmp;

	tmp = NULL;
	tmp = head;
	if (head == NULL)
		head = create();
	else
	{
		tmp = create();
		tmp->next = head;
		head = tmp;
	}
	return (head);
}

t_fillit	*get_figure(char *line, t_fillit *head, char set)
{
	int			x;
	int			y;
	int			l;
	int			xmin;

	x = 0;
	y = 0;
	l = 0;
	xmin = set_figure(line);
	while (l < 4)
	{
		x = 0;
		while (line[x] == '.')
			x++;
		if (line[x] == '#')
		{
			while (line[x] == '#')
				head->coordinate[y][x++ - xmin] = set;
			y++;
		}
		line = ft_strchr(line, '\n');
		line++;
		l++;
	}
	return (head);
}

int			set_figure(char *line)
{
	int			xmin;
	int			x;

	xmin = 4;
	x = 0;
	while (*(line) != '\0')
	{
		if (*(line) == '\n')
		{
			x = 0;
			line++;
		}
		while (*(line) == '.')
		{
			x++;
			line++;
		}
		if (*(line) == '#')
		{
			if (xmin > x)
				xmin = x;
			line++;
		}
	}
	return (xmin);
}

t_fillit	*read_figure(char *line, int fd, t_fillit *head)
{
	int			ret;
	t_fillit	*tmp;
	char		set;
	int			i;

	ret = 0;
	tmp = head;
	set = 'A';
	i = 0;
	while ((ret = read(fd, line, 21)) != 0)
	{
		line[20] = '\0';
		head = new_node(head);
		head = get_figure(line, head, set);
		set++;
		i++;
	}
	return (head);
}
