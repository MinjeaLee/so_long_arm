#include "so_long.h"

void game_init(game *g, char *filename)
{
	g->mlx = mlx_init();
	g->img = img_init(g->mlx);
	g->m = parser(filename);
	g->win = mlx_new_window(g->mlx, g->m->width * 32, g->m->height * 32, "so_long");
	put_img(g, 0, 0);
	// render_map(g);
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
	printf("0");
	game_init(g, argv[1]);
	// mlx_loop(g->mlx);

	return 0;
}