#include "so_long.h"

//TODO : 3. 맵 유효성 체크

player *game_init(game *g)
{
	player *p;

	p = (player *)malloc(sizeof(player));
	find_start(g, p);
	count_keys(g, p);
	p->walk_count = 0;
	return (p);
}

void find_start(game *g, player *p)
{
	int i;
	int j;

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

void count_keys(game *g, player *p)
{
	int i;
	int j;

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
	//! 맵에 key가 하나 이상인지
	if (p->keys == 0)
		print_error("no keys\n");
}