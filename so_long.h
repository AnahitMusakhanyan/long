/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusakha <amusakha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:44:47 by amusakha          #+#    #+#             */
/*   Updated: 2023/11/06 18:59:00 by amusakha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17

# define A_KEY		0
# define S_KEY		1
# define D_KEY		2
# define W_KEY		13
# define ESC		53

# define SPRITE_H	32
# define SPRITE_W	32

# include<stdlib.h>
# include"./libft/libft.h"
# include<mlx.h>
# include"./libft/get_next_line.h"
#include<stdio.h>

typedef struct s_map
{
	char			c;
	int				x;
	int				y;
	int				w;
	int				h;
	struct s_map	*next;
}					t_map;

typedef struct s_help
{
	int				coll;
	int				px;
	int				py;
	int				w;
	int				h;
	void			*mlx;
	void			*win;
	void			*ptr;
	char			**map;
	char			**map2;
	int				step;
}					t_help;

int 	flood_fill(t_help **str, int x, int y, int *exit);
void	drawing(t_help **str, char c, int xi, int yi);
int		draw_map(t_help **str);
void	player(t_help **str);
void	memory_error(void);
void	arg_error(void);
void	map_error(void);
void	free_res(char **res);
void	free_map(t_help **str, char *s);
int	free_data(t_help *str, char *s);
void	make_map(char **res, t_help **str);
void	all_map(t_help **str);
int	check_coll(char **res);
void	check_data(char **res);
char	**check_newlines(char *ptr, char **res);
char	*get_map(char *ptr);
int	up(t_help **str, int x, int y);
int	down(t_help **str, int x, int y);
int	right(t_help **str, int x, int y);
int	left(t_help **str, int x, int y);
void    moving(int key, t_help **str, int x, int y);
void    all_coll(t_help **str);
void    ft_close(t_map *data);

#endif