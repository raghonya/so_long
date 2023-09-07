/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:43:01 by raghonya          #+#    #+#             */
/*   Updated: 2023/02/25 17:43:04 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
/*
	This is game about Hummer and policemen with their cars.

	Your goal is to kill all policemen and not been crashed by their cars.

	If you want win, go to garage after killing all policemen.

	If you want to change game theme, change the 
	image paths from here(header file macros).

	If your player haven`t images in 4 directions, you may
	change directions.c file, only comment
	lines where is written macros which you don`t use

	And please, keep images size in 50PX in width and height,
	or change it from below
*/

# define PX 50
# define PLAYER_UP "images/hummerup.xpm"
# define P_RIGHT "images/hummerright.xpm"
# define P_DOWN "images/hummerdown.xpm"
# define P_LEFT "images/hummerleft.xpm"
# define COIN_RIGHT "images/policemanleft.xpm"
# define COIN_LEFT "images/policemanright.xpm"
# define COIN_EXTRA "images/parkacpoliceman.xpm"
# define ENEMY_RED "images/policecarred.xpm"
# define ENEMY_BLUE "images/policecarblue.xpm"
# define EXIT "images/garage.xpm"
# define WALL "images/shenq.xpm"
# define SPACE "images/floor.xpm"

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "printf/ft_printf.h"

# define MAIN int main (int argc, char **argv)

# ifdef __linux__
#  define ESC 65307
#  define UP 65362
#  define RIGHT 65363
#  define DOWN 65364
#  define LEFT 65361
#  define UP2 119
#  define RIGHT2 100
#  define DOWN2 115
#  define LEFT2 97
# else
#  define ESC 53
#  define UP 13
#  define RIGHT 2
#  define DOWN 1
#  define LEFT 0
#  define UP2 126
#  define RIGHT2 124
#  define DOWN2 125
#  define LEFT2 123
# endif

typedef struct s_img
{
	char	*path;
	void	*icon;
}	t_img;

typedef struct s_mlx
{
	t_img	p;
	t_img	w;
	t_img	e;
	t_img	s;
	t_img	c;
	t_img	en;
	void	*mlx;
	void	*win;
	char	*map_path;
	char	**map;
	char	**args;
	int		map_x;
	int		map_y;
	int		px_x;
	int		px_y;
	int		i;
	int		j;
	int		count;
	int		flag;
}	t_mlx;

typedef struct s_count
{
	int	e_count;
	int	c_count;
	int	p_count;
	int	e_tox;
	int	e_syun;
}	t_count;

int		counts(char **split, char **split2);
char	**map_check(char *file, int *c_count);
void	for_up(t_mlx *mlx);
void	for_right(t_mlx *mlx);
void	for_down(t_mlx *mlx);
void	for_left(t_mlx *mlx);
void	create_map(t_mlx *mlx);
void	universal_func(int a, char *s);
void	to_up(t_mlx *mlx, int *count);
void	to_right(t_mlx *mlx, int *count);
void	to_down(t_mlx *mlx, int *count);
void	to_left(t_mlx *mlx, int *count);
int		animation(t_mlx *mlx);
void	run_map(t_mlx *mlx);

#endif
