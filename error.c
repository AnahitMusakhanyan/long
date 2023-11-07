/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusakha <amusakha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:28:24 by amusakha          #+#    #+#             */
/*   Updated: 2023/11/07 17:34:32 by amusakha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	memory_error(void)
{
	ft_putstr_fd("failed to allocate memory", 1);
	exit(1);
}

void	arg_error(void)
{
	ft_putstr_fd("the number of arguments is incorrect", 1);
	exit(1);
}	

void	map_error(void)
{
	ft_putstr_fd("incorrect map", 1);
	exit(1);
}
