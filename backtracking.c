/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusakha <amusakha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:27:36 by amusakha          #+#    #+#             */
/*   Updated: 2023/11/07 17:44:24 by amusakha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int flood_fill(t_help **str, int x, int y, int *exit)
{
	static int	score;
	t_help *tmp = *str;
	
	if (tmp->map[y][x] == 'C')
		score++;
	if (tmp->map[y][x] == 'E')
		*exit = 1;
	if (x < 0 || y < 0 || x >= tmp->w || y >= tmp->h)
		return (score);
	if (tmp->map[y][x] != '0' && tmp->map[y][x] != 'P' && tmp->map[y][x] != 'C')
		return (score);
	if (tmp->map[y][x] == '-')
		return (score);
	tmp->map[y][x] = '-';
	flood_fill(&tmp, x + 1, y, exit);
	flood_fill(&tmp, x - 1, y, exit);
	flood_fill(&tmp, x, y + 1, exit);
	flood_fill(&tmp, x, y - 1, exit);
	return (score);
}
