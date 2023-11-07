/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusakha <amusakha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:27:31 by amusakha          #+#    #+#             */
/*   Updated: 2023/11/07 17:11:42 by amusakha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"	

void	get_h(char **res)
{
	int	i;
	int	h;

	i = -1;
	h = 0;
	while(res[++i])
		h++;
}

char	**call_functions(char *ptr, char **res)
{
	ptr = get_map(ptr);
	res = check_newlines(ptr, res);
	check_data(res);
	return (res);
}

void	init_data(t_map **data, char **res)
{
	int		w;
	int		h;
	int		i;
	t_map	*tmp;

	h = 0;
	i = 0;
	w = ft_strlen(res[0]);
	tmp = (*data);
	while (res[h])
		h++;
	while (++i < h * w)
	{
		(*data)->next = (t_map *)malloc(sizeof(t_map));
		(*data)->w = w;
		(*data)->h = h;
		(*data) = (*data)->next;
	}
	(*data)->next = NULL;
	(*data) = tmp;
}

void	score_check(t_help **str, char **res)
{
	int		max_score;
	int 	exx;

	max_score = flood_fill(str, (*str)->px, (*str)->py, &exx);
	(*str)->coll = check_coll(res);
	if (exx != 1 && (*str)->coll != max_score)
	{
		free_res(res);
		free_map(str, "map error");
	}
}

int	main(int ac, char **av)
{
	t_map	*data;
	char	*ptr;
	char	**res;
	t_help	*str;

	(void) av;
	if (ac != 2)
		arg_error();
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		map_error();
	ptr = NULL;
	res = NULL;
	res = call_functions(ptr, res);
	data = (t_map *)malloc(sizeof(t_map));
	init_data(&data, res);
	str = malloc(sizeof(t_help));
	str->h = data->h;
	str->w = data->w;
	all_map(&str);
	make_map(res, &str);
	score_check(&str, res);
	str->step = 0;
	str->mlx = mlx_init();
	str->win = mlx_new_window(str->mlx, (str->w - 1) * SPRITE_W,
			(str->h - 1) * SPRITE_H, "so_long");
	player(&str);
	draw_map(&str);
	mlx_hook(str->win, X_EVENT_KEY_PRESS, 1L << 0, key_press, &str);
	mlx_hook(str->win, X_EVENT_KEY_EXIT, 1L << 0, ft_close, &str);
	mlx_expose_hook(str->win, sharing, &str);
	mlx_loop(str->mlx);
	return (0);
}
