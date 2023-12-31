/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusakha <amusakha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:29:04 by amusakha          #+#    #+#             */
/*   Updated: 2023/11/07 17:33:38 by amusakha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

// void	free_res(char **res)
// {
// 	int	i;

// 	i = 0;
// 	while (res[i])
// 	{
// 		free(res[i]);
// 		i++;
// 	}
// 	free(res);
// }

void	free_map(t_help **str, char *s)
{
	// free(str);
	(void) str;
	ft_putstr_fd(s, 1);
	exit(0);
}

int	free_data(t_help *str, char *s)
{
	int	yi;

	yi = 0;
	ft_putstr_fd(s, 1);
	mlx_destroy_window(str->mlx, str->win);
	exit(0);
}
