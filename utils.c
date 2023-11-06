/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:01:00 by amusakha          #+#    #+#             */
/*   Updated: 2023/11/06 17:42:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void    all_coll(t_help **str)
{
	int	xi;
	int	yi;
	int	coll;

	yi = 0;
	coll = 0;
	while (++yi < str->h - 1)
	{
		xi = 0;
		while (++xi < str->w - 1)
			if (str->map2[yi][xi] == 'C')
				coll++;
	}
	if (coll == 0)
		free_map(str, "you won\n");
	else
		ft_putstr_fd("collect all the eggs\n", 1);
	return (0);
}

void    ft_close(t_map *data)
{
	free_map(str, "game is closed");
}