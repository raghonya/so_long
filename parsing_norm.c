/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:42:31 by raghonya          #+#    #+#             */
/*   Updated: 2023/02/25 17:42:32 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix(char **split, char **split2)
{
	int	i;

	i = -1;
	while (split[++i])
	{	
		free(split[i]);
		free(split2[i]);
	}
	free(split);
	free(split2);
}

void	find_valid_path(char **map, int len, int ln, int cl)
{
	if (ln < 1 || cl < 1 || map[ln + 1] == NULL || cl == len - 1 \
		|| map[ln][cl] == '1' || map[ln][cl] == 'K')
		return ;
	map[ln][cl] = '1';
	find_valid_path(map, len, ln - 1, cl);
	find_valid_path(map, len, ln, cl + 1);
	find_valid_path(map, len, ln + 1, cl);
	find_valid_path(map, len, ln, cl - 1);
}

void	check_valid_path(char **map, int len, t_count a)
{
	int	i;

	find_valid_path(map, len, a.e_tox, a.e_syun);
	i = -1;
	while (map[++i])
		universal_func (ft_strchr(map[i], 'P') || \
		ft_strchr(map[i], 'C'), "Valid path chka\n");
}

int	counts_norm(char **s, t_count *a, int *i)
{
	int		j;

	while (s[++(*i)])
	{
		j = -1;
		while (s[*i][++j])
		{	
			if (s[*i][j] == 'E')
			{
				a->e_tox = *i;
				a->e_syun = j;
				a->e_count++;
			}
			else if (s[*i][j] == 'P')
				a->p_count++;
			else if (s[*i][j] == 'C')
				a->c_count++;
		}
	}
	return (a->e_syun);
}

int	counts(char **split, char **split2)
{
	t_count		a;
	int			i;
	size_t		len;
	int			c;

	universal_func (!split || !(*split) || !split2 || !(*split2), \
		"Malloci xndir\n");
	len = ft_strlen(split[0]);
	i = -1;
	a.p_count = 0;
	a.c_count = 0;
	a.e_count = 0;
	i = counts_norm(split, &a, &i);
	c = a.c_count;
	universal_func((a.e_count != 1 || a.p_count != 1 || a.c_count == 0), \
		"Symbolneri qanaki xndir\n");
	check_valid_path(split2, len, a);
	free_matrix(split, split2);
	return (c);
}
