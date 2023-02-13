#include "so_long.h"

int clear_game(game *g)
{
	g->p->walk_count++;
	printf("%s %d%s\n", "Congratulations! You have", g->p->walk_count, "steps.");
	exit(0);
}

void press_w(game *g)
{
	printf("%c\n", g->m->world[g->p->x - 1][g->p->y]);
	if (g->m->world[g->p->x - 1][g->p->y] == '1')
		return;
	else if (g->m->world[g->p->x - 1][g->p->y] == 'C')
	{
		g->cnt_key++;
		g->p->walk_count++;
		g->m->world[g->p->x - 1][g->p->y] = 'P';
		g->m->world[g->p->x][g->p->y] = '0';
		g->p->x--;
		render_map(g);
	}
	else if (g->m->world[g->p->x - 1][g->p->y] == 'E' && g->keys == g->cnt_key)
		clear_game(g);
	else if (g->m->world[g->p->x - 1][g->p->y] == 'E' && g->keys != g->cnt_key)
		return;
	else
	{
		g->p->walk_count++;
		g->m->world[g->p->x - 1][g->p->y] = 'P';
		g->m->world[g->p->x][g->p->y] = '0';
		g->p->x--;
		render_map(g);
	}
}

void press_a(game *g)
{
	if (g->m->world[g->p->x][g->p->y - 1] == '1')
		return;
	else if (g->m->world[g->p->x][g->p->y - 1] == 'C')
	{
		g->cnt_key++;
		g->p->walk_count++;
		g->m->world[g->p->x][g->p->y - 1] = 'P';
		g->m->world[g->p->x][g->p->y] = '0';
		g->p->y--;
		render_map(g);
	}
	else if (g->m->world[g->p->x][g->p->y - 1] == 'E' && g->keys == g->cnt_key)
		clear_game(g);
	else if (g->m->world[g->p->x][g->p->y - 1] == 'E' && g->keys != g->cnt_key)
		return;
	else
	{
		g->p->walk_count++;
		g->m->world[g->p->x][g->p->y - 1] = 'P';
		g->m->world[g->p->x][g->p->y] = '0';
		g->p->y--;
		render_map(g);
	}
}

void press_s(game *g)
{
	if (g->m->world[g->p->x + 1][g->p->y] == '1')
		return;
	else if (g->m->world[g->p->x + 1][g->p->y] == 'C')
	{
		g->cnt_key++;
		g->p->walk_count++;
		g->m->world[g->p->x + 1][g->p->y] = 'P';
		g->m->world[g->p->x][g->p->y] = '0';
		g->p->x++;
		render_map(g);
	}
	else if (g->m->world[g->p->x + 1][g->p->y] == 'E' && g->keys == g->cnt_key)
		clear_game(g);
	else if (g->m->world[g->p->x + 1][g->p->y] == 'E' && g->keys != g->cnt_key)
		return;
	else
	{
		g->p->walk_count++;
		g->m->world[g->p->x + 1][g->p->y] = 'P';
		g->m->world[g->p->x][g->p->y] = '0';
		g->p->x++;
		render_map(g);
	}
}

void press_d(game *g)
{
	if (g->m->world[g->p->x][g->p->y + 1] == '1')
		return;
	else if (g->m->world[g->p->x][g->p->y + 1] == 'C')
	{
		g->cnt_key++;
		g->p->walk_count++;
		g->m->world[g->p->x][g->p->y + 1] = 'P';
		g->m->world[g->p->x][g->p->y] = '0';
		g->p->y++;
		render_map(g);
	}
	else if (g->m->world[g->p->x][g->p->y + 1] == 'E' && g->keys == g->cnt_key)
		clear_game(g);
	else if (g->m->world[g->p->x][g->p->y + 1] == 'E' && g->keys != g->cnt_key)
		return;
	else
	{
		g->p->walk_count++;
		g->m->world[g->p->x][g->p->y + 1] = 'P';
		g->m->world[g->p->x][g->p->y] = '0';
		g->p->y++;
		render_map(g);
	}
}