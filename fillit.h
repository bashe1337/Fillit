/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bashe <bashe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:13:49 by bashe             #+#    #+#             */
/*   Updated: 2019/11/20 18:56:03 by bashe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FILLIT_H
# define FILLIT_FILLIT_H

# include "libft/libft.h"
#include "stdio.h"

typedef struct		s_fillit
{
	int				*coordinate;
	char			character;
	struct s_fillit	*next;
}					t_fillit;

int					validation(char *line);
int					validString(char *line, int *i, int *sh);
void				sh_counter(char *line, int *i, int **sh);
t_fillit			*get_figure(char *line, int fd, t_fillit *head);
t_fillit			*create(char *line);
t_fillit			*new_node(char *line, t_fillit *head);

#endif
