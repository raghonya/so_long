/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:42:47 by raghonya          #+#    #+#             */
/*   Updated: 2023/02/25 17:42:49 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

int	close_map(int key, t_mlx *mlx)
{
	static int	count;
	char		*s;

	if (mlx->flag == 0)
		exit(0);
	if (key == 53)
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	else if (key == 13 || key == 126)
		to_up(mlx, &count);
	else if (key == 2 || key == 124)
		to_right(mlx, &count);
	else if (key == 1 || key == 125)
		to_down(mlx, &count);
	else if (key == 0 || key == 123)
		to_left(mlx, &count);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->w.icon, 0, 0);
	s = ft_itoa(count);
	mlx_string_put(mlx->mlx, mlx->win, 1, 10, 0x00FF0000, s);
	free(s);
	int j = -1;
	while (mlx->map[++j])
		printf ("%s\n", mlx->map[j]);
	printf ("\n");
	return (0);
}

void	destroy(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->p.icon);
	mlx_destroy_image(mlx->mlx, mlx->e.icon);
	mlx_destroy_image(mlx->mlx, mlx->c.icon);
	mlx_destroy_image(mlx->mlx, mlx->s.icon);
	mlx_destroy_image(mlx->mlx, mlx->w.icon);
	mlx_destroy_image(mlx->mlx, mlx->en.icon);
}

void	run_map(t_mlx *mlx)
{
	static int	a = -1;

	++a;
	if (!mlx->args[a])
	{
		destroy(mlx);
		mlx->flag = 0;
		mlx->win = mlx_new_window(mlx->mlx, 200, \
		200, "WINNER!!!!!!!!!!!!!!!!!");
		mlx_string_put(mlx->mlx, mlx->win, 50, \
			100, 0x00FF00, "YOU WOOOOOOON🥳🥳🥳!!!");
		mlx_string_put(mlx->mlx, mlx->win, 50, \
			110, 0xFFFFFF, "Press any key to");
		mlx_string_put(mlx->mlx, mlx->win, 50, \
			120, 0xFFFFFF, "close the window");
		mlx_hook(mlx->win, 2, 0, &close_map, mlx);
		mlx_hook(mlx->win, 17, 0, &close_window, mlx);
		mlx_loop(mlx->mlx);
	}
	mlx->map = map_check(mlx->args[a], &(mlx->count));
	create_map(mlx);
	mlx_string_put(mlx->mlx, mlx->win, 1, 10, 0x00FF0000, "0");
	mlx_hook(mlx->win, 2, 0, &close_map, mlx);
	mlx_hook(mlx->win, 17, 0, &close_window, mlx);
	mlx_loop(mlx->mlx);
}

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	int			i;
	int			j;

	i = 0;
	universal_func(argc == 1, "No map, please add *.ber files in arguments\n");
	mlx.args = malloc(argc * sizeof(char *));
	while (++i < argc)
	{
		mlx.args[i - 1] = argv[i];
		j = i - 1;
		while (--j > -1)
			universal_func (!ft_strncmp(mlx.args[i - 1], mlx.args[j], \
				ft_strlen(mlx.args[j])), "Nuyn mapy 1 angamic avel mi tveq");
	}
	mlx.args[i - 1] = NULL;
	mlx.flag = 1;
	run_map(&mlx);
	return (0);
}
