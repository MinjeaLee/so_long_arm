/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:12:53 by mi                #+#    #+#             */
/*   Updated: 2023/02/19 18:32:34 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**duplicate(t_game *g)
{
	char	**map_temp;
	int		i;
	int		j;

	i = 0;
	map_temp = (char **)malloc(sizeof(char *) * g->m->height);
	while (i < g->m->height)
	{
		j = 0;
		map_temp[i] = (char *)malloc(sizeof(char) * ft_strlen(g->m->world[0]));
		while (j < ft_strlen(g->m->world[0]))
		{
			map_temp[i][j] = g->m->world[i][j];
			j++;
		}
		i++;
	}
	return (map_temp);
}

int	dfs_e(int x, int y, char **map)
{
	int	count;

	if (map[x][y] == '1')
		return (0);
	if (map[x][y] != 'V')
	{
		if (map[x][y] == 'E')
		{
			map[x][y] = 'V';
			return (1);
		}
		map[x][y] = 'V';
		count = 0;
		count += dfs_e(x - 1, y, map);
		count += dfs_e(x, y + 1, map);
		count += dfs_e(x + 1, y, map);
		count += dfs_e(x, y - 1, map);
		return (count);
	}
	return (0);
}

int	dfs_c(int x, int y, char **map)
{
	int	count;

	if (map[x][y] == '1' || map[x][y] == 'E')
		return (0);
	if (map[x][y] != 'V')
	{
		if (map[x][y] == 'C')
		{
			map[x][y] = 'V';
			return (1);
		}
		map[x][y] = 'V';
		count = 0;
		count += dfs_c(x - 1, y, map);
		count += dfs_c(x, y + 1, map);
		count += dfs_c(x + 1, y, map);
		count += dfs_c(x, y - 1, map);
		return (count);
	}
	return (0);
}

int	has_valid_path(t_game *g)
{
	char	**map_temp_c;
	char	**map_temp_e;
	int		c_count;
	int		e_count;

	map_temp_c = duplicate(g);
	map_temp_e = duplicate(g);
	c_count = dfs_c(g->p->x, g->p->y, map_temp_c);
	e_count = dfs_e(g->p->x, g->p->y, map_temp_e);
	if (c_count != g->p->keys)
		return (0);
	if (e_count != 1)
		return (0);
	return (1);
}
