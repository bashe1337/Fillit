/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bashe <bashe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:23:27 by bashe             #+#    #+#             */
/*   Updated: 2019/11/20 20:33:38 by bashe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fillit	*create(char *line)
{
	t_fillit	*new_elem;

	new_elem = (t_fillit *)malloc(sizeof(t_fillit));
	if (new_elem == NULL)
		return (NULL);
	new_elem->coordinate = (int *)malloc(sizeof(int) + 8);
	ft_bzero(new_elem->coordinate, 8);
	new_elem->next = NULL;
	return (new_elem);
}

t_fillit	*new_node(char *line, t_fillit *head)
{
	t_fillit	*tmp;
	
	if (head == NULL)
		head = create(line);
	else
	{
		tmp = create(line);
		tmp->next = head;
		head = tmp;
	}
	return (head);
}

t_fillit	*get_figure(char *line, int fd, t_fillit *head)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	head = new_node(line, head);
	while (get_next_line(fd, &line) && y < 4)
	{
		x = 0;
		while (line[x] == '.')
			x++;
		while (line[x] == '#')
		{
			*(head->coordinate) = x++;
			head->coordinate++;
			*(head->coordinate) = y;
		}
		y++;
	}
	return (head);
}
