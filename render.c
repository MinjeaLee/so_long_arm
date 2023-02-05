#include "so_long.h"

image *img_init(void *mlx)
{
	image *img;
	int width;
	int height;

	img = (image *)malloc(sizeof(image));
	img->door_open = mlx_xpm_file_to_image(mlx, "./images/door_open.xpm", &width, &height);
	// printf("1 %p", img->door_open);
	img->door_closed = mlx_xpm_file_to_image(mlx, "./images/door_closed.xpm", &width, &height);
	// printf("2 %p", img->door_closed);
	img->food = mlx_xpm_file_to_image(mlx, "./images/food.xpm", &width, &height);
	// printf("3 %p", img->food);
	img->player = mlx_xpm_file_to_image(mlx, "./images/player.xpm", &width, &height);
	// printf("4 %p", img->player);
	img->wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &width, &height);
	// printf("5 %p", img->wall);
	img->land = mlx_xpm_file_to_image(mlx, "./images/land.xpm", &width, &height);

	return (img);
}

void put_img(game *g, int w, int h)
{
	// printf("%c", g->m->world[h][w]);
	mlx_put_image_to_window(g->mlx, g->win, g->img->land, w * 32, h * 32);
	// printf("%c\n", g->m->world[h][w]);
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
	else
		mlx_put_image_to_window(g->mlx, g->win, g->img->land, w * 32, h * 32);
}

void render_map(game *g)
{
	int w;
	int h;

	// for (int i = 0; i < g->m->height; i++)
	// {
	// 	printf("%s", g->m->world[i]);
	// }
	h = 0;
	while (h < g->m->height)
	{
		w = 0;
		while (w < g->m->width)
		{
			put_img(g, w, h);
			w++;
		}
		h++;
	}
}

