/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:45:39 by amusakha          #+#    #+#             */
/*   Updated: 2023/11/06 17:41:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	up(t_help **str)
{
	(*str)->map2[y][x] = '0';
	(*str)->map2[y + 1][x] = 'P';
	t->step++;
	return (0);
}

int	down(t_help **str)
{
	(*str)->map2[y][x] = '0';
	(*str)->map2[y - 1][x] = 'P';
	t->step++;
	return (0);
}

int	right(t_help **str)
{
	(*str)->map2[y][x] = '0';
	(*str)->map2[y][x + 1] = 'P';
	t->step++;
	return (0);
}

int	left(t_help **str)
{
	(*str)->map2[y][x] = '0';
	(*str)->map2[y][x - 1] = 'P';
	t->step++;
	return (0);
}

void    moving(int key, t_help **str, int x, int y)
{
	if (key == A_KEY && (*str)->map2[y][x - 1] == 'E')
		all_coll(str);
	else if (key == A_KEY && (*str)->map2[y][x - 1] != '1')
		left(str);
	if (key == D_KEY && (*str)->map2[y][x + 1] == 'E')
		all_coll(str);
	else if (key == D_KEY && (*str)->map2[y][x + 1] != '1')
		right(str);
	if (key == S_KEY && (*str)->map2[y + 1][x] == 'E')
		all_coll(str);
	else if (key == S_KEY && (*str)->map2[y + 1][x] != '1')
		up(str);
	if (key == W_KEY && (*str)->map2[y - 1][x] == 'E')
		all_coll(str);
	else if (key == W_KEY && (*str)->map2[y - 1][x] != '1')
		down(str);
}