/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusakha <amusakha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:29:04 by amusakha          #+#    #+#             */
/*   Updated: 2023/11/01 19:05:54 by amusakha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	free_res(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

// void	stackfree(t_map *data)
// {
// 	free(data->win);
// 	ft_putstr_fd("error", 1);
// 	exit(1);
// }

void	free_map(t_help *str, char *s)
{
	free(str);
	ft_putstr_fd(s, 1);
	exit(1);
}

int	map_free(t_help *str, char *s)
{
	int	yi;

	yi = 0;
	ft_putstr_fd(s, 1);
	mlx_destroy_window(str->mlx, str->win);
	// free(data->map);
	// while (yi < data->h)
	// {
	// 	free(data->map[data->y]);
	// 	yi++;
	// }
	exit(0);
}
