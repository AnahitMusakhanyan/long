/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusakha <amusakha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:01:00 by amusakha          #+#    #+#             */
/*   Updated: 2023/11/07 16:59:46 by amusakha         ###   ########.fr       */
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
	while (++yi < (*str)->h - 1)
	{
		xi = 0;
		while (++xi < (*str)->w - 1)
			if ((*str)->map2[yi][xi] == 'C')
				coll++;
	}
	if (coll == 0)
		free_map(str, "you won\n");
	else
		ft_putstr_fd("collect all the eggs\n", 1);
}

int    ft_close(t_help **str)
{
	free_map(str, "game is closed");
	return (0);
}

int	sharing(t_help **str)
{
	int	xi;
	int	yi;

	yi = 0;
	while (yi < (*str)->h - 1)
	{
		xi = 0;
		while (xi < (*str)->w - 1)
		{
			drawing(str, (*str)->map2[yi][xi], xi, yi);
			xi++;
		}
		yi++;
	}
	return (0);
}

int	key_press(int key, t_help **str)
{
	int	stepped;

	stepped = (*str)->step;
	if (key == ESC)
		free_map(str, "game iver\n");
	else
		moving(key, str, (*str)->px, (*str)->py);
	if (stepped != (*str)->step)
	{
		ft_putstr_fd("stepped: ", 1);
		ft_putnbr_fd((*str)->step, 1);
		ft_putstr_fd("\n", 1);
	}
	sharing(str);
	return (0);
}