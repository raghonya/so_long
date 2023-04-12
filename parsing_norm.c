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

int	rec_for_c(char **split, int ln, int cl, int *Count)
{
	if (ln < 1 || cl < 1 || split[ln + 1] == NULL \
		|| (size_t)cl == ft_strlen(split[0]) - 1 \
		|| split[ln][cl] == '1' || split[ln][cl] == 'K')
		return (0);
	else if (split[ln][cl] == 'C')
		*Count -= 1;
	split[ln][cl] = '1';
	if (*Count == 0)
		return (77);
	if (rec_for_c(split, ln - 1, cl, Count) > 0)
		return (777);
	if (rec_for_c(split, ln, cl - 1, Count) > 0)
		return (777);
	if (rec_for_c(split, ln + 1, cl, Count) > 0)
		return (777);
	if (rec_for_c(split, ln, cl + 1, Count) > 0)
		return (777);
	return (-1);
}

int	rec_for_e(char **split, size_t len, int ln, int cl)
{
	if (ln < 1 || cl < 1 || split[ln + 1] == NULL || (size_t)cl == len - 1 \
		|| split[ln][cl] == '1' || split[ln][cl] == 'K')
		return (0);
	else if (split[ln][cl] == 'P')
		return (100);
	split[ln][cl] = '1';
	if (rec_for_e(split, len, ln - 1, cl) > 0)
		return (777);
	if (rec_for_e(split, len, ln, cl - 1) > 0)
		return (777);
	if (rec_for_e(split, len, ln + 1, cl) > 0)
		return (777);
	if (rec_for_e(split, len, ln, cl + 1) > 0)
		return (777);
	return (-1);
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
	universal_func((rec_for_e(split, len, a.e_tox, a.e_syun) != 777 \
		|| rec_for_c(split2, a.e_tox, a.e_syun, &a.c_count) != 777), \
		"Valid path chka\n");
	free_matrix(split, split2);
	return (c);
}
