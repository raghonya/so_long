/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:52:08 by raghonya          #+#    #+#             */
/*   Updated: 2023/03/02 15:52:10 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	eli_norm(t_mlx *mlx, char *s)
{
	int	x;

	x = 0;
	if (mlx->map[mlx->i][mlx->j] == 'K')
		exit(0);
	mlx_destroy_image(mlx->mlx, mlx->p.icon);
	mlx->p.icon = mlx_xpm_file_to_image(mlx->mlx, \
		s, &x, &x);
	universal_func(!(mlx->p.icon), "Nkari sxal path\n");
	if (mlx->map[mlx->i][mlx->j] == 'C' && mlx->count--)
		mlx->map[mlx->i][mlx->j] = '7';
}

void	to_up(t_mlx *mlx, int *count)
{
	int	x;

	x = 0;
	if (mlx->map[mlx->i - 1][mlx->j] != 49)
	{
		*count += 1;
		mlx->i -= 1;
		eli_norm (mlx, PLAYER_UP);
		mlx->px_y -= PX;
		if (mlx->map[mlx->i][mlx->j] == 'E' && mlx->count == 0)
			exit(0);
		mlx_put_image_to_window (mlx->mlx, mlx->win, \
			mlx->p.icon, mlx->px_x, mlx->px_y);
		mlx_put_image_to_window (mlx->mlx, mlx->win, \
			mlx->s.icon, mlx->px_x, mlx->px_y + PX);
		if (mlx->map[mlx->i + 1][mlx->j] == '7')
			for_up(mlx);
		if (mlx->map[mlx->i + 1][mlx->j] == 'E')
			mlx_put_image_to_window (mlx->mlx, mlx->win, \
				mlx->e.icon, mlx->px_x, mlx->px_y + PX);
		ft_printf ("%d\n", *count);
	}
}

void	to_right(t_mlx *mlx, int *count)
{
	int	x;

	x = 0;
	if (mlx->map[mlx->i][mlx->j + 1] != 49)
	{
		*count += 1;
		mlx->j += 1;
		eli_norm (mlx, P_RIGHT);
		mlx->px_x += PX;
		if (mlx->map[mlx->i][mlx->j] == 'E' && mlx->count == 0)
			exit(0);
		mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->p.icon, \
			mlx->px_x, mlx->px_y);
		mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->s.icon, \
			mlx->px_x - PX, mlx->px_y);
		if (mlx->map[mlx->i][mlx->j - 1] == '7')
			for_right(mlx);
		if (mlx->map[mlx->i][mlx->j - 1] == 'E')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->e.icon, \
				mlx->px_x - PX, mlx->px_y);
		ft_printf ("%d\n", *count);
	}
}

void	to_down(t_mlx *mlx, int *count)
{
	int	x;

	x = 0;
	if (mlx->map[mlx->i + 1][mlx->j] != 49)
	{
		*count += 1;
		mlx->i += 1;
		eli_norm (mlx, P_DOWN);
		mlx->px_y += PX;
		if (mlx->map[mlx->i][mlx->j] == 'E' && mlx->count == 0)
			exit(0);
		mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->p.icon, \
			mlx->px_x, mlx->px_y);
		mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->s.icon, \
			mlx->px_x, mlx->px_y - PX);
		if (mlx->map[mlx->i - 1][mlx->j] == '7')
			for_down(mlx);
		if (mlx->map[mlx->i - 1][mlx->j] == 'E')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->e.icon, \
				mlx->px_x, mlx->px_y - PX);
		ft_printf ("%d\n", *count);
	}
}

void	to_left(t_mlx *mlx, int *count)
{
	int	x;

	x = 0;
	if (mlx->map[mlx->i][mlx->j - 1] != 49)
	{
		*count += 1;
		mlx->j -= 1;
		eli_norm (mlx, P_LEFT);
		mlx->px_x -= PX;
		if (mlx->map[mlx->i][mlx->j] == 'E' && mlx->count == 0)
			exit(0);
		mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->p.icon, \
			mlx->px_x, mlx->px_y);
		mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->s.icon, \
			mlx->px_x + PX, mlx->px_y);
		if (mlx->map[mlx->i][mlx->j + 1] == '7')
			for_left(mlx);
		if (mlx->map[mlx->i][mlx->j + 1] == 'E')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->e.icon, \
				mlx->px_x + PX, mlx->px_y);
		ft_printf ("%d\n", *count);
	}
}
