/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusakha <amusakha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:01:00 by amusakha          #+#    #+#             */
/*   Updated: 2023/11/02 15:20:52 by amusakha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

// void	collcheck(t_map *data)
// {
// 	int coll;
// 	int xi;
// 	int yi;
// 	t_map *cur;

// 	cur = data;
// 	xi = -1;
// 	coll = 0;
// 	while (++xi < data->w)
// 	{
// 		yi = -1;
// 		while (++yi < data->h)
// 		{
// 			if (data->map[data->x][data->y] == 'C')
// 				coll++;
// 			data = data->next;
// 		}	
// 	}
// 	data = cur;
// 	if (coll == 0)
// 		map_free(data, "you won");
// 	else
// 		ft_putstr_fd("collect all of the eggs", 1);;
// }

// void    ft_close(t_map *data)
// {
// 	map_free(data, "game is closed");
// }