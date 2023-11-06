/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusakha <amusakha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:27:25 by amusakha          #+#    #+#             */
/*   Updated: 2023/11/02 15:57:09 by amusakha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	make_map(char **res, t_help **str)
{	
	int		i;
	int		j;

	i = 0;
	while ((*str) && i < (*str)->h)
	{
		j = 0;
		while ((*str) && j < (*str)->w)
		{
			(*str)->map[i][j] = res[i][j];
			(*str)->map2[i][j] = res[i][j];
			j++;
		}
		i++;
	}
}

void	all_map(t_help **str)
{
	int	i;

	i = 0;
	(*str)->map = (char **)malloc(((*str)->h) * sizeof(char *));
	(*str)->map2 = (char **)malloc(((*str)->h) * sizeof(char *));
	if ((*str)->map == NULL || (*str)->map2 == NULL)
		memory_error();
	while ((*str) && i < (*str)->h)
	{
		(*str)->map[i] = (char *)malloc(((*str)->w) * sizeof(char));
		(*str)->map2[i] = (char *)malloc(((*str)->w) * sizeof(char));
		if ((*str)->map[i] == NULL || (*str)->map2[i] == NULL)
		{
			free_map((*str), "failed to allocation memory");
			free((*str)->map);
		}
		i++;
	}
}

void	check_coll(char **res)
{
	int		i;
	int		j;
	int		c;
	
	i = -1;
	c = 0;
	while(res[i])
	{
		j = 0;
		while(res[i][j])
		{
			if (res[i][j] == 'C')
				c++;
		}
		i++;
	}
	if (!(c > 0))
		map_error();
}

void	check_data(char **res)
{
	int		e;
	int		p;
	int		i;
	int		j;

	i = -1;
	e = 0;
	p = 0;
	while (res[++i])
	{
		j = -1;
		while (res[i][++j])
		{
			if (res[i][j] == '1' || res[i][j] == '0' || res[i][j] == 'C')
				continue ;
			else if (res[i][j] == 'E')
				e++;
			else if (res[i][j] == 'P')
				p++;
			else
				map_error();
		}
	}
	if (p != 1 || e != 1)
		map_error();
}

char	**check_newlines(char *ptr, char **res)
{
	int	i;

	i = 0;
	if (!ptr)
		exit (1);
	while (ptr[i])
	{
		if (ptr[i] && ptr[i + 1] && ptr[i] == '\n' && ptr[i + 1] == '\n')
			map_error();
		i++;
	}
	res = ft_split(ptr, '\n');
	return (res);
}

char	*get_map(char *ptr)
{
	char	*line;
	char	*str;
	int		fd;

	(void) ptr;
	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("error opening the file\n", 1);
		exit (1);
	}
	str = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (!str)
			str = line;
		else
			str = ft_strjoin(str, line);
	}
	ptr = ft_strtrim(str, "\n");
	return (ptr);
}
