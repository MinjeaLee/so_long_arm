/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 23:01:08 by mi                #+#    #+#             */
/*   Updated: 2023/02/19 18:32:34 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*game_init(t_game *g)
{
	t_player	*p;

	p = (t_player *)malloc(sizeof(t_player));
	find_start(g, p);
	count_keys(g, p);
	p->walk_count = 0;
	return (p);
}

void	find_start(t_game *g, t_player *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < g->m->height)
	{
		while (j < g->m->width)
		{
			if (g->m->world[i][j] == 'P')
			{
				p->x = i;
				p->y = j;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	count_keys(t_game *g, t_player *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < g->m->height)
	{
		while (j < g->m->width)
		{
			if (g->m->world[i][j] == 'C')
				p->keys++;
			j++;
		}
		j = 0;
		i++;
	}
	if (p->keys == 0)
		print_error("no keys\n");
}
	/*
	! 맵에 key가 하나 이상인지
	*/
