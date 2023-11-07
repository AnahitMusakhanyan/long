/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusakha <amusakha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:30:16 by amusakha          #+#    #+#             */
/*   Updated: 2023/11/07 19:27:47 by amusakha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	drawing(t_help **str, char c, int xi, int yi)
{
	int w = (*str)->w;
	int h = (*str)->h;
	
	if (c == '1')
		(*str)->ptr = mlx_xpm_file_to_image((*str)->mlx, "./images/wall.xpm", &w, &h);
	else if (c == '0')
		(*str)->ptr = mlx_xpm_file_to_image((*str)->mlx, "./images/path.xpm", &w, &h);
	else if (c == 'P')
		(*str)->ptr = mlx_xpm_file_to_image((*str)->mlx, "./images/player.xpm", &w, &h);
	else if (c == 'E')
		(*str)->ptr = mlx_xpm_file_to_image((*str)->mlx, "./images/exit.xpm", &w, &h);
	else if (c == 'C')
		(*str)->ptr = mlx_xpm_file_to_image((*str)->mlx, "./images/coll.xpm", &w, &h);
	mlx_put_image_to_window((*str)->mlx, (*str)->win, (*str)->ptr, SPRITE_W * xi, SPRITE_H * yi);
	mlx_destroy_image((*str)->mlx, (*str)->ptr);
}

int	draw_map(t_help **str)
{
	int	xi;
	int	yi;

	yi = -1;
	while (++yi < (*str)->h - 1)
	{
		xi = -1;
		while (++xi < (*str)->w - 1)
			drawing(str, (*str)->map2[yi][xi], xi, yi);
	}
	return (0);
}

void	player(t_help **str)
{
	int	x;
	int	y;

	y = 0;
	while (y < (*str)->h)
	{
		x = 0;
		while (x < (*str)->w)
		{
			if ((*str)->map[y][x] == 'P')
			{
				(*str)->px = x;
				(*str)->py = y;
			}
			x++;
		}
		y++;
	}
}