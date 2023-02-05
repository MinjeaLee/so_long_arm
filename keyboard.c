#include "so_long.h"

player *init()
{
	player *p;

	p = (player *)malloc(sizeof(player));
	p->x = 4;
	p->y = 2;
	return (p);
}

void press_w(game *g)
{
	printf("Press W");
	if (g->m->world[g->p->x - 1][g->p->y] == '1')
		return;
	else if (g->m->world[g->p->x - 1][g->p->y] == 'C')
	{
		g->cnt_key++;
		g->p->walk_count++;
		g->m->world[g->p->x - 1][g->p->y] = '0';
		g->p->x--;
		render_map(g);
	}
	else if (g->m->world[g->p->x - 1][g->p->y] == 'E' && g->keys == g->cnt_key)
	{
		printf("You win!\n");
		exit(0);
	}
	else if (g->m->world[g->p->x - 1][g->p->y] == 'E' && g->keys != g->cnt_key)
		return;
	else
	{
		g->p->walk_count++;
		g->p->x--;
		render_map(g);
	}
}