/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:51:57 by raghonya          #+#    #+#             */
/*   Updated: 2023/03/02 15:51:58 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	func_for_p_norm(t_mlx *mlx, int i, int j, int x)
{
	mlx->i = i;
	mlx->j = j;
	mlx->px_x = x;
	mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->p.icon, x, mlx->px_y);
}

void	images(t_mlx *mlx)
{
	int		x;

	mlx->en.path = ENEMY_RED;
	mlx->e.path = EXIT;
	mlx->w.path = WALL;
	mlx->c.path = COIN_LEFT;
	mlx->s.path = SPACE;
	mlx->p.path = PLAYER_UP;
	mlx->p.icon = mlx_xpm_file_to_image(mlx->mlx, mlx->p.path, &x, &x);
	mlx->s.icon = mlx_xpm_file_to_image(mlx->mlx, mlx->s.path, &x, &x);
	mlx->c.icon = mlx_xpm_file_to_image(mlx->mlx, mlx->c.path, &x, &x);
	mlx->w.icon = mlx_xpm_file_to_image(mlx->mlx, mlx->w.path, &x, &x);
	mlx->e.icon = mlx_xpm_file_to_image(mlx->mlx, mlx->e.path, &x, &x);
	mlx->en.icon = mlx_xpm_file_to_image(mlx->mlx, mlx->en.path, &x, &x);
	universal_func (!mlx->p.icon || !mlx->s.icon || !mlx->c.icon \
		|| !mlx->w.icon || !mlx->e.icon || !mlx->en.icon, \
		"Nkarnerd texum chen kam sxal path\n");
}

void	kreativs_chheriqec(t_mlx *mlx, int i, int *x, int y)
{
	int	j;

	j = -1;
	*x = 0;
	while (mlx->map[i][++j])
	{
		if (mlx->map[i][j] == '0')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->s.icon, *x, y);
		else if (mlx->map[i][j] == '1')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->w.icon, *x, y);
		else if (mlx->map[i][j] == 'P')
		{
			mlx->px_y = y;
			func_for_p_norm (mlx, i, j, *x);
		}
		else if (mlx->map[i][j] == 'E')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->e.icon, *x, y);
		else if (mlx->map[i][j] == 'C')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->c.icon, *x, y);
		else if (mlx->map[i][j] == 'K')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->en.icon, *x, y);
		*x += 50;
	}
}

void	fill_map(t_mlx *mlx)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	y = 0;
	images(mlx);
	while (mlx->map[++i])
	{
		kreativs_chheriqec(mlx, i, &x, y);
		y += 50;
	}
}

void	create_map(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	universal_func (!(mlx->mlx), "Inicializacneluc mi ban traqec\n");
	mlx->map_y = 0;
	while (mlx->map[mlx->map_y])
		mlx->map_y++;
	mlx->map_x = PX * ft_strlen(mlx->map[0]);
	mlx->map_y = PX * mlx->map_y;
	mlx->win = mlx_new_window(mlx->mlx, mlx->map_x, \
		mlx->map_y, "./so_long");
	universal_func (!(mlx->win), "Patuhany bacveluc mi ban traqec\n");
	mlx_loop_hook(mlx->mlx, &animation, mlx);
	fill_map(mlx);
}
