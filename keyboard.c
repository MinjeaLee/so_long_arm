#include "so_long.h"

player *init()
{
	player *p;

	p = (player *)malloc(sizeof(player));
	p->x = 3;
	p->y = 1;
	p->walk_count = 0;
	return (p);
}

void press_w(game *g)
{
	printf("%d %d\n", g->p->x, g->p->y);
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
	{
		printf("You win!\n");
		exit(0);
	}
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
	for (int i = 0; i < g->m->height; i++)
	{
		for (int j = 0; j < g->m->width; j++)
		{
			printf("%c", g->m->world[i][j]);
		}
		printf("\n");
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
	{
		printf("You win!\n");
		exit(0);
	}
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
	for (int i = 0; i < g->m->height; i++)
	{
		for (int j = 0; j < g->m->width; j++)
		{
			printf("%c", g->m->world[i][j]);
		}
		printf("\n");
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
	{
		printf("You win!\n");
		exit(0);
	}
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
	for (int i = 0; i < g->m->height; i++)
	{
		for (int j = 0; j < g->m->width; j++)
		{
			printf("%c", g->m->world[i][j]);
		}
		printf("\n");
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
	{
		printf("You win!\n");
		exit(0);
	}
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
	for (int i = 0; i < g->m->height; i++)
	{
		for (int j = 0; j < g->m->width; j++)
		{
			printf("%c", g->m->world[i][j]);
		}
		printf("\n");
	}
}