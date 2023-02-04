#include "so_long.h"

image *img_init(void *mlx)
{
	image *img;
	int width;
	int height;

	img = (image *)malloc(sizeof(image));
	img->door_open = mlx_xpm_file_to_image(mlx, "./img/door_open.xpm", &width, &height);
	img->door_closed = mlx_xpm_file_to_image(mlx, "./img/door_closed.xpm", &width, &height);
	img->food = mlx_xpm_file_to_image(mlx, "./img/food.xpm", &width, &height);
	img->player = mlx_xpm_file_to_image(mlx, "./img/player.xpm", &width, &height);
	img->wall = mlx_xpm_file_to_image(mlx, "./img/wall.xpm", &width, &height);
	img->land = mlx_xpm_file_to_image(mlx, "./img/land.xpm", &width, &height);
	return (img);
}

void put_img(game *g, int w, int h)
{
	mlx_put_image_to_window(g->mlx, g->win, g->img->land, w * 32, h * 32);
	if (g->m->world[h][w] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img->wall, w * 32, h * 32);
	else if (g->m->world[h][w] == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->img->player, w * 32, h * 32);
	else if (g->m->world[h][w] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->img->food, w * 32, h * 32);
	else if (g->m->world[h][w] == 'E' && g->keys == g->cnt_key)
		mlx_put_image_to_window(g->mlx, g->win, g->img->door_open, w * 32, h * 32);
	else if (g->m->world[h][w] == 'E' && g->keys != g->cnt_key)
		mlx_put_image_to_window(g->mlx, g->win, g->img->door_closed, w * 32, h * 32);
}

// void render_map(game *g)
// {
// 	int w;
// 	int h;

// 	h = 0;
// 	while (h < g->m->height)
// 	{
// 		w = 0;
// 		while (w < g->m->width - 1)
// 		{
// 			put_img(g, w, h);
// 			w++;
// 		}
// 		h++;
// 	}
// }

