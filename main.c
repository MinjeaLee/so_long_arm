#include "so_long.h"

void game_init(game *g, char *filename)
{
	g->mlx = mlx_init();
	g->img = img_init(g->mlx);
	g->m = parser(filename);
	g->p = init();
	g->keys = 1;
	g->win = mlx_new_window(g->mlx, g->m->width * 32, g->m->height * 32, "so_long");
	render_map(g);
}

int key_press(int keycode, game *g)
{
	printf("keycode: %d", keycode);
	if (keycode == KEY_W)
	{
		press_w(g);
	}
	return (0);
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
	// printf("0");
	game_init(g, argv[1]);
	mlx_hook(g->win, X_EVENT_KEY_RELEASE, 0, &key_press, g);
	// mlx_hook(g->win, X_EVENT_KEY_PRESS, 1L << 0, &key_press, g);


	mlx_loop(g->mlx);

	return 0;
}