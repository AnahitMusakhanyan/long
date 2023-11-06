/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:27:36 by amusakha          #+#    #+#             */
/*   Updated: 2023/11/06 15:16:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int flood_fill(t_help **str, int x, int y, int *exit)
{
	static int	score;

	if ((*str)->map[y][x] == 'C')
		score++;
	if ((*str)->map[y][x] == 'E')
		*exit = 1;
	if (x < 0 || y < 0 || x >= (*str)->w || y >= (*str)->h)
		return (score);
	if ((*str)->map[y][x] != '0' && (*str)->map[y][x] != 'P' && (*str)->map[y][x] != 'C')
		return (score);
	if ((*str)->map[y][x] == '-')
		return (score);
	(*str)->map[y][x] = '-';
	flood_fill(str, x + 1, y, exit);
	flood_fill(str, x - 1, y, exit);
	flood_fill(str, x, y + 1, exit);
	flood_fill(str, x, y - 1, exit);
	return (score);
}
