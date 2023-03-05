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

#include "so_long_bonus.h"

void	images(t_mlx *mlx)
{
	int		x;

	mlx->E.path = "images/garage.xpm";
	mlx->W.path = "images/shenq.xpm";
	mlx->C.path = "images/policeman.xpm";
	mlx->S.path = "images/floor.xpm";
	mlx->P.path = "images/hummerright.xpm";
	mlx->P.icon = mlx_xpm_file_to_image(mlx->mlx, mlx->P.path, &x, &x);
	mlx->S.icon = mlx_xpm_file_to_image(mlx->mlx, mlx->S.path, &x, &x);
	mlx->C.icon = mlx_xpm_file_to_image(mlx->mlx, mlx->C.path, &x, &x);
	mlx->W.icon = mlx_xpm_file_to_image(mlx->mlx, mlx->W.path, &x, &x);
	mlx->E.icon = mlx_xpm_file_to_image(mlx->mlx, mlx->E.path, &x, &x);
	if (!mlx->P.icon || !mlx->S.icon || !mlx->C.icon \
		|| !mlx->W.icon || !mlx->E.icon)
	{
		ft_printf ("Error\nNkarnerd texum chen kam sxal path\n");
		exit(1);
	}
}

void	kreativs_chheriqec(t_mlx *mlx, int i, int *x, int y)
{
	int	j;

	j = -1;
	*x = 0;
	while (mlx->map[i][++j])
	{
		if (mlx->map[i][j] == '0')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->S.icon, *x, y);
		else if (mlx->map[i][j] == '1')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->W.icon, *x, y);
		else if (mlx->map[i][j] == 'P')
		{
			mlx->i = i;
			mlx->j = j;
			mlx->px_x = *x;
			mlx->px_y = y;
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->P.icon, *x, y);
		}
		else if (mlx->map[i][j] == 'E')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->E.icon, *x, y);
		else if (mlx->map[i][j] == 'C')
			mlx_put_image_to_window (mlx->mlx, mlx->win, mlx->C.icon, *x, y);
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
	if (!mlx->mlx)
	{
		ft_printf ("Error\nInicializacneluc mi ban traqec\n");
		exit(1);
	}
	mlx->map_y = 0;
	while (mlx->map[mlx->map_y])
		mlx->map_y++;
	mlx->map_x = PX * ft_strlen(mlx->map[0]);
	mlx->map_y = PX * mlx->map_y;
	mlx->win = mlx_new_window(mlx->mlx, mlx->map_x, \
		mlx->map_y, "./so_long");
	if (!mlx->win)
	{
		ft_printf ("Error\nPatuhany bacveluc mi ban traqec\n");
		exit(1);
	}
	fill_map(mlx);
}
