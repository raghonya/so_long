/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:42:02 by raghonya          #+#    #+#             */
/*   Updated: 2023/02/25 17:42:25 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	universal_func(int a, char *s)
{
	if (a)
	{
		ft_printf ("Error\n%s", s);
		exit(1);
	}
}

void	fd_size(char **s, char *file)
{
	int		fd;
	int		i;
	int		sym_count;
	char	a;

	i = 0;
	sym_count = 0;
	universal_func(ft_strncmp(ft_strrchr(file, '.'), ".ber", 4), \
		"Invalid file\n");
	fd = open(file, O_RDONLY);
	while (read(fd, &a, 1) > 0)
		sym_count++;
	close(fd);
	fd = open(file, O_RDONLY);
	*s = malloc (sym_count + 1);
	universal_func (read (fd, *s, sym_count) <= 0, "Invalid or empty file\n");
	(*s)[sym_count] = 0;
	*s = ft_strtrim(*s, "\n");
}

void	map_symbols_and_uxxankyun(char **split, int j)
{
	size_t	len;
	int		i;

	i = -1;
	len = ft_strlen(split[0]);
	while (split[++i])
	{
		j = -1;
		universal_func(len != ft_strlen(split[i]), "Not uxxankyun map\n");
		while (split[i][++j])
			universal_func(split[i][j] != '0' && split[i][j] != '1' \
				&& split[i][j] != 'C' && split[i][j] != 'E' \
				&& split[i][j] != 'P' && split[i][j] != '\n' \
				&& split[i][j] != 'K', "Invalid symbols\n");
		j = -1;
		if (split[i + 1] == NULL || i == 0)
			while (split[i][++j])
				universal_func (split[i][j] != 7 * 7, "Invalid map\n");
		else
			while (split[i][++j])
				universal_func (split[i][0] != 49 \
					|| split[i][len - 1] != 49, "Invalid map\n");
	}
}

char	**map_check(char *file, int *c_count)
{
	char	**split;
	int		len;
	char	*s;
	int		i;

	fd_size(&s, file);
	universal_func(!s, "...\n");
	split = ft_split(s, '\n');
	universal_func (!split || !(*split), \
		"Malloci xndir kam datark file\n");
	map_symbols_and_uxxankyun(split, 2147483647);
	len = ft_strlen(split[0]);
	i = -1;
	while (split[++i])
		universal_func(i > 20 || len > 40, "Shat mec map\
		\nMaximum 20 tox, 40 syun\n");
	*c_count = counts (ft_split(s, '\n'), ft_split(s, '\n'));
	free(s);
	return (split);
}
