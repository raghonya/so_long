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

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define PX 50

typedef	struct s_img
{
	char	*path;
	void	*icon;
}	t_img;

typedef	struct s_mlx
{
	t_img	P;
	t_img	W;
	t_img	E;
	t_img	S;
	t_img	C;
	void	*mlx;
	void	*win;
	char	**map;
	int		map_x;
	int		map_y;
	int		px_x;
	int		px_y;
	int		i;
	int		j;
	int		count;
}	t_mlx;


typedef struct s_count
{
	int	e_count;
	int	c_count;
	int	p_count;
	int	e_tox;
	int	e_syun;
	int	nl;
}	t_count;

# include <math.h>
# include <mlx.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "printf/ft_printf.h"

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

#endif
