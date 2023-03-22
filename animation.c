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

void	anim_norm(t_mlx *mlx, char a, char *s)
{
	int	x;
	int	i;
	int	j;

	mlx_destroy_image(mlx->mlx, mlx->c.icon);
	mlx->c.icon = mlx_xpm_file_to_image(mlx->mlx, s, &x, &x);
	universal_func (!(mlx->c.icon), "Nkari sxal path\n");
	i = -1;
	while (mlx->map[++i])
	{
		j = -1;
		while (mlx->map[i][++j])
			if (mlx->map[i][j] == a)
				mlx_put_image_to_window(mlx->mlx, mlx->win, \
					mlx->c.icon, j * PX, i * PX);
	}
}

int	animation(t_mlx *mlx)
{
	static int	i;
	static int	j;
	static int	k;
	static int	heriqa;

	if (mlx->flag == 0)
		return (0);
	if (i % 10000 == 0)
		anim_norm(mlx, 'C', COIN_LEFT);
	if (j % 20000 == 0)
		anim_norm(mlx, 'C', COIN_RIGHT);
	if (k % 7000 == 0)
		anim_norm(mlx, 'K', ENEMY_RED);
	if (heriqa % 14000 == 0)
		anim_norm(mlx, 'K', ENEMY_BLUE);
	i++;
	j++;
	k++;
	heriqa++;
	return (0);
}
