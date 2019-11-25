/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bashe <bashe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:32:19 by bashe             #+#    #+#             */
/*   Updated: 2019/11/25 20:59:23 by bashe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FILLIT_H
# define FILLIT_FILLIT_H
# include "libft/libft.h"

typedef struct		s_fillit
{
	char			**coordinate;
	char			character;
	struct s_fillit	*next;
}					t_fillit;

int					validation(char *line);
int					valid_file(char *line, int *i, int *l, int *sh);
int					valid_string(char *line, int *i, int *sh, int *t);
void				touch_sides(char *line, int *i, int **sh, int **l);
int					valid_tetro(char *line, int *l, int *sh, int *i);
t_fillit			*get_figure(char *line, t_fillit *head, char set);
t_fillit			*create(void);
t_fillit			*new_node(t_fillit *head);
t_fillit			*read_figure(char *line, int fd, t_fillit *head);
int					set_figure(char *line);

#endif
