/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusakha <amusakha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:45:39 by amusakha          #+#    #+#             */
/*   Updated: 2023/11/02 15:20:10 by amusakha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

// void	down(t_map *data)
// {
// 	data->map[data->x][data->y] = '0';
// 	data->map[data->x][data->y - 1] = 'P';
// 	data->step++;
// }

// void	up(t_map *data)
// {
// 	data->map[data->x][data->y] = '0';
// 	data->map[data->x][data->y + 1] = 'P';
// 	data->step++;
// }

// void	right(t_map *data)
// {
// 	data->map[data->x][data->y] = '0';
// 	// data->map[data->x++] senc anem te che
// 	data->map[data->x + 1][data->y] = 'P';
// 	data->step++;
// }

// void	left(t_map *data)
// {
// 	data->map[data->x][data->y] = '0';
// 	data->map[data->x - 1][data->y] = 'P';
// 	data->step++;
// }

// void    move(int key, t_map *data)
// {
// 	if (key == A_KEY && data->map[data->y][data->x - 1] == 'E')
// 		collcheck(data);
// 	else if (key == A_KEY && data->map[data->y][data->x - 1] != '1')
// 		left(data);
// 	if (key == D_KEY && data->map[data->y][data->x + 1] == 'E')
// 		collcheck(data);
// 	else if (key == D_KEY && data->map[data->y][data->x + 1] != '1')
// 		right(data);
// 	if (key == S_KEY && data->map[data->y + 1][data->x] == 'E')
// 		collcheck(data);
// 	else if (key == S_KEY && data->map[data->y + 1][data->x] != '1')
// 		up(data);
// 	if (key == W_KEY && data->map[data->y - 1][data->x] == 'E')
// 		collcheck(data);
// 	else if (key == W_KEY && data->map[data->y - 1][data->x] != '1')
// 		down(data);
// }

// int    key_press(int key, void *ptr, int x, int y)
// {
// 	t_map *data;
// 	int	stepped;

// 	// printf("henlo Gev");
// 	data = ptr;
// 	stepped = data->step; // game.step
// 	if (key == ESC)
// 		free_map(data, "game over\n");
// 	else
// 		move(key, data);
// 	if (stepped != data->step) //
// 	{
// 		ft_putstr_fd("stepped: ", 1);
// 		ft_putnbr_fd(data->step, 1); //
// 		ft_putstr_fd("\n", 1);
// 	}
// 	draw_map(data, x, y);
// 	return (0);
// }