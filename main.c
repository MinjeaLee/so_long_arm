#include "so_long.h"

void game_init(game *g, char *filename)
{
	g->mlx = mlx_init();
	g->img = img_init(g->mlx);
	printf("%p\n", g->img);
	printf("%p\n", g->img->land);
	g->m = parser(filename);
	g->p = init();
	g->keys = 1;
	g->win = mlx_new_window(g->mlx, g->m->width * 32, g->m->height * 32, "so_long");
	printf("%p\n", g->win);
	render_map(g);
	printf("1\n");
}


int key_press(int keycode, game *g)
{
	printf("1\n");
	if (keycode == KEY_W)
	{
		press_w(g);
	}
	else if(keycode == KEY_A)
	{
		press_a(g);
	}
	else if(keycode == KEY_S)
	{
		press_s(g);
	}
	else if(keycode == KEY_D)
	{
		press_d(g);
	}
	else if(keycode == KEY_ESC)
	{
		exit(0);
	}

	return 0 ;
}

int main(int argc, char **argv)
{
	game *g;

	g = (game *)malloc(sizeof(game));
	if (argc != 2)
	{
		ft_putstr_fd("Error filename\n", 2);
		exit(1);
	}
	game_init(g, argv[1]);
	printf("2\n");
	mlx_hook(g->win, X_EVENT_KEY_PRESS, 2, &key_press, g);

	mlx_loop(g->mlx);

	return 0;
}