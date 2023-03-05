/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:09:57 by raghonya          #+#    #+#             */
/*   Updated: 2023/03/04 19:09:58 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	anim_norm(t_mlx *mlx, char *s)
{
	int	x;
	int	i;
	int	j;

	mlx->c.icon = mlx_xpm_file_to_image(mlx->mlx, s, &x, &x);
	universal_func (!(mlx->c.icon), "Nkari sxal path\n");
	i = -1;
	while (mlx->map[++i])
	{
		j = -1;
		while (mlx->map[i][++j])
			if (mlx->map[i][j] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, \
					mlx->c.icon, j * PX, i * PX);
	}
}

int	animation(t_mlx *mlx)
{
	static int	i;
	static int	j;

	if (i % 10000 == 0)
		anim_norm(mlx, COIN_LEFT);
	if (j % 20000 == 0)
		anim_norm(mlx, COIN_RIGHT);
	i++;
	j++;
	return (0);
}
