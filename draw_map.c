/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusakha <amusakha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:30:16 by amusakha          #+#    #+#             */
/*   Updated: 2023/11/02 16:01:43 by amusakha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

// void	drawing(t_help *str, char c, int xi, int yi)
// {
// 	if (c == '1')
// 		str->ptr = mlx_xpm_file_to_image(str, "./images/wall.xpm", &str->w, &str->h);
// 	else if (c == '0')
// 		str->ptr = mlx_xpm_file_to_image(str, "./images/path.xpm", &str->w, &str->h);
// 	else if (c == 'P')
// 		str->ptr = mlx_xpm_file_to_image(str, "./images/player.xpm", &str->w, &str->h);
// 	else if (c == 'E')
// 		str->ptr = mlx_xpm_file_to_image(str, "./images/exit.xpm", &str->w, &str->h);
// 	else if (c == 'C')
// 		str->ptr = mlx_xpm_file_to_image(str, "./images/coll.xpm", &str->w, &str->h);
// 	mlx_put_image_to_window(str->mlx, str->win, str->ptr, str->w * xi, str->h *yi);
// 	mlx_destroy_image(str->mlx, str->ptr);
// }

// int	draw_map(t_help *str,int w, int h)
// {
// 	int	xi;
// 	int	yi;

// 	yi = -1;
// 	while (str && ++yi < h - 1)
// 	{
// 		xi = -1;
// 		while (str && ++xi < w - 1)
// 		{
// 			drawing(str, str->map[str->x][str->y], xi, yi);
// 			str = str->next;
// 		}
// 	}

// 	return (0);
// }

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