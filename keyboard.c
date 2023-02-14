/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:09:15 by mi                #+#    #+#             */
/*   Updated: 2023/02/14 18:13:34 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"

int clear_game(player *p)
{
	p->walk_count++;
	printf("%s %d%s\n", "Congratulations! You have", p->walk_count, "steps.");
	exit(0);
}

void press_w(game *g, player *p)
{
	if (g->m->world[p->x - 1][p->y] == '1')
		return;
	else if (g->m->world[p->x - 1][p->y] == 'C')
	{
		// p->cnt_key++;
		p->cnt_key++;
		p->walk_count++;
		g->m->world[p->x - 1][p->y] = 'P';
		g->m->world[p->x][p->y] = '0';
		p->x--;
		render_map(g);
	}
	else if (g->m->world[p->x - 1][p->y] == 'E' && p->keys == p->cnt_key)
		clear_game(p);
	else if (g->m->world[p->x - 1][p->y] == 'E' && p->keys != p->cnt_key)
		return;
	else
	{
		p->walk_count++;
		g->m->world[p->x - 1][p->y] = 'P';
		g->m->world[p->x][p->y] = '0';
		p->x--;
		render_map(g);
	}
}

void press_a(game *g, player *p)
{
	if (g->m->world[p->x][p->y - 1] == '1')
		return;
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
		clear_game(p);
	else if (g->m->world[p->x][p->y - 1] == 'E' && p->keys != p->cnt_key)
		return;
	else
	{
		p->walk_count++;
		g->m->world[p->x][p->y - 1] = 'P';
		g->m->world[p->x][p->y] = '0';
		p->y--;
		render_map(g);
	}
}

void press_s(game *g, player *p)
{
	if (g->m->world[p->x + 1][p->y] == '1')
		return;
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
		clear_game(p);
	else if (g->m->world[p->x + 1][p->y] == 'E' && p->keys != p->cnt_key)
		return;
	else
	{
		p->walk_count++;
		g->m->world[p->x + 1][p->y] = 'P';
		g->m->world[p->x][p->y] = '0';
		p->x++;
		render_map(g);
	}
}

void press_d(game *g, player *p)
{
	if (g->m->world[p->x][p->y + 1] == '1')
		return;
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
		clear_game(p);
	else if (g->m->world[p->x][p->y + 1] == 'E' && p->keys != p->cnt_key)
		return;
	else
	{
		p->walk_count++;
		g->m->world[p->x][p->y + 1] = 'P';
		g->m->world[p->x][p->y] = '0';
		p->y++;
		render_map(g);
	}
}