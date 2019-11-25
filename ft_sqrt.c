/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bashe <bashe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 20:47:00 by bashe             #+#    #+#             */
/*   Updated: 2019/11/22 21:03:21 by bashe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_sqrt(int a)
{
	float	x;
	int	i;

	x = 1.0;
	i = 0;
	while (x * x < a)
		x *= 10;
	while (i < 10)
	{
		x = x + a / x;
		x = x / 2;
		i++;
	}
	return (x);
}
