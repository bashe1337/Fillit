/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bashe <bashe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:23:27 by bashe             #+#    #+#             */
/*   Updated: 2019/11/23 21:10:47 by bashe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
// #include <stdio.h>

t_fillit    *create(char *line)
{
    t_fillit    *new_elem;
    int            y;
    
    y = 0;
    new_elem = (t_fillit *)ft_memalloc(sizeof(t_fillit));
    new_elem->coordinate = (char **)ft_memalloc(sizeof(char *) * 4);
    while (y < 4)
    {
        new_elem->coordinate[y] = (char *)ft_memalloc(sizeof(char) * 4);
        y++;
    }
    new_elem->next = NULL;
    return (new_elem);
}

t_fillit    *new_node(char *line, t_fillit *head)
{
    t_fillit    *tmp;
    
    tmp = NULL;
    tmp = head;
    if (head == NULL)
    {
        head = create(line);
        // head->next = NULL;
    }
    else
    {
        tmp = create(line);                // may be need fix
        tmp->next = head;
        head = tmp;
    }
    return (head);
}

t_fillit    *get_figure(char *line, int fd, t_fillit *head, char set)
{
    int            x;
    int            y;
    int            r;
    
    x = 0;
    y = 0;
    r = 0;
    head = new_node(line, head);
    while (get_next_line(fd, &line) && y < 4)
    {
        x = 0;
        while (line[x] == '.')
            x++;
        if (line[x] == '#')
        {
            while (line[x] == '#')
                head->coordinate[r][x++] = set;
            r++;
        }
        y++;
    }
    return (head);
}

