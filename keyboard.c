/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:09:15 by mi                #+#    #+#             */
/*   Updated: 2023/02/19 18:32:34 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_game(t_game *g)
{
	g->p->walk_count++;
	printf("%s %d%s\n", "Congratulations! ", g->p->walk_count, "steps.");
	exit_game(g);
}

void	press_w(t_game *g, t_player *p)
{
	if (g->m->world[p->x - 1][p->y] == '1')
		return ;
	else if (g->m->world[p->x - 1][p->y] == 'C')
	{
		p->cnt_key++;
		p->walk_count++;
		g->m->world[p->x - 1][p->y] = 'P';
		g->m->world[p->x][p->y] = '0';
		p->x--;
		render_map(g);
	}
	else if (g->m->world[p->x - 1][p->y] == 'E' && p->keys == p->cnt_key)
		clear_game(g);
	else if (g->m->world[p->x - 1][p->y] == 'E' && p->keys != p->cnt_key)
		return ;
	else
	{
		p->walk_count++;
		g->m->world[p->x - 1][p->y] = 'P';
		g->m->world[p->x][p->y] = '0';
		p->x--;
		render_map(g);
	}
}

void	press_a(t_game *g, t_player *p)
{
	if (g->m->world[p->x][p->y - 1] == '1')
		return ;
	else if (g->m->world[p->x][p->y - 1] == 'C')
	{
		p->cnt_key++;
		p->walk_count++;
		g->m->world[p->x][p->y - 1] = 'P';
		g->m->world[p->x][p->y] = '0';
		p->y--;
		render_map(g);
	}
	else if (g->m->world[p->x][p->y - 1] == 'E' && p->keys == p->cnt_key)
		clear_game(g);
	else if (g->m->world[p->x][p->y - 1] == 'E' && p->keys != p->cnt_key)
		return ;
	else
	{
		p->walk_count++;
		g->m->world[p->x][p->y - 1] = 'P';
		g->m->world[p->x][p->y] = '0';
		p->y--;
		render_map(g);
	}
}

void	press_s(t_game *g, t_player *p)
{
	if (g->m->world[p->x + 1][p->y] == '1')
		return ;
	else if (g->m->world[p->x + 1][p->y] == 'C')
	{
		p->cnt_key++;
		p->walk_count++;
		g->m->world[p->x + 1][p->y] = 'P';
		g->m->world[p->x][p->y] = '0';
		p->x++;
		render_map(g);
	}
	else if (g->m->world[p->x + 1][p->y] == 'E' && p->keys == p->cnt_key)
		clear_game(g);
	else if (g->m->world[p->x + 1][p->y] == 'E' && p->keys != p->cnt_key)
		return ;
	else
	{
		p->walk_count++;
		g->m->world[p->x + 1][p->y] = 'P';
		g->m->world[p->x][p->y] = '0';
		p->x++;
		render_map(g);
	}
}

void	press_d(t_game *g, t_player *p)
{
	if (g->m->world[p->x][p->y + 1] == '1')
		return ;
	else if (g->m->world[p->x][p->y + 1] == 'C')
	{
		p->cnt_key++;
		p->walk_count++;
		g->m->world[p->x][p->y + 1] = 'P';
		g->m->world[p->x][p->y] = '0';
		p->y++;
		render_map(g);
	}
	else if (g->m->world[p->x][p->y + 1] == 'E' && p->keys == p->cnt_key)
		clear_game(g);
	else if (g->m->world[p->x][p->y + 1] == 'E' && p->keys != p->cnt_key)
		return ;
	else
	{
		p->walk_count++;
		g->m->world[p->x][p->y + 1] = 'P';
		g->m->world[p->x][p->y] = '0';
		p->y++;
		render_map(g);
	}
}
