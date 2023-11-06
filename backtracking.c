/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusakha <amusakha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:27:36 by amusakha          #+#    #+#             */
/*   Updated: 2023/11/02 16:05:37 by amusakha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

// int	flood_fill(t_map *data, int x, int y, int *exit_is_accessable)
// {
// 	static int	count_of_collect_reached;

// 	if (data->map[x][y] == 'C')
// 		count_of_collect_reached++;
// 	if (data->map[x][y] == 'E')
// 		*exit_is_accessable = 1;
// 	if (x < 0 || y < 0 || x >= data->w || y >= data->h)
// 		return (count_of_collect_reached);
// 	if (data->map[x][y] != '0' && data->map[x][y] != 'P' && data->map[x][y] != 'C')
// 		return (count_of_collect_reached);
// 	if (data->map[x][y] == 'V')
// 		return (count_of_collect_reached);
// 	data->map[x][y] = 'V';
// 	flood_fill(data, x + 1, y, exit_is_accessable);
// 	flood_fill(data, x - 1, y, exit_is_accessable);
// 	flood_fill(data, x, y + 1, exit_is_accessable);
// 	flood_fill(data, x, y - 1, exit_is_accessable);
// 	return (count_of_collect_reached);
// }

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
