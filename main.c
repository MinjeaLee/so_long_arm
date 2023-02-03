#include <stdlib.h>
#include <stdio.h>
#include "so_long.h"

// #define X_EVENT_KEY_PRESS 2
// #define X_EVENT_KEY_RELEASE 3

// #define KEY_ESC 53
// #define KEY_W 13
// #define KEY_A 0
// #define KEY_S 1
// #define KEY_D 2

// typedef struct s_param
// {
// 	int x;
// 	int y;
// } t_param;

// void param_init(t_param *param)
// {
// 	param->x = 3;
// 	param->y = 4;
// }

// int key_press(int keycode, t_param *param)
// {
// 	static int a = 0;

// 	if (keycode == KEY_W)
// 		param->y++;
// 	else if (keycode == KEY_S)
// 		param->y--;
// 	else if (keycode == KEY_A)
// 		param->x--;
// 	else if (keycode == KEY_D)
// 		param->x++;
// 	else if (keycode == KEY_ESC)
// 		exit(0);
// 	printf("x: %d, y: %d\n", param->x, param->y);
// 	return (0);
// }

// int main(void)
// {
// 	void *mlx;
// 	void *win;
// 	t_param param;

// 	param_init(&param);
// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 500, 500, "mlx_project");
// 	mlx_hook(win, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
// 	mlx_loop(mlx);
// }

// int main()
// {
// 	void *mlx;
// 	void *win;
// 	void *img;
// 	void *img2;
// 	void *img3;
// 	void *img4;
// 	void *img5;
// 	void *img6;
// 	int img_width;
// 	int img_height;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 500, 500, "my_mlx");
// 	img = mlx_xpm_file_to_image(mlx, "./images/land.xpm", &img_width, &img_height);
// 	img2 = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &img_width, &img_height);
// 	img3 = mlx_xpm_file_to_image(mlx, "./images/player.xpm", &img_width, &img_height);
// 	img4 = mlx_xpm_file_to_image(mlx, "./images/food.xpm", &img_width, &img_height);
// 	img5 = mlx_xpm_file_to_image(mlx, "./images/door_open.xpm", &img_width, &img_height);
// 	img6 = mlx_xpm_file_to_image(mlx, "./images/door_closed.xpm", &img_width, &img_height);
// 	mlx_put_image_to_window(mlx, win, img, 0, 0);
// 	mlx_put_image_to_window(mlx, win, img, 32, 0);
// 	mlx_put_image_to_window(mlx, win, img2, 32, 0);
// 	mlx_put_image_to_window(mlx, win, img, 64, 0);
// 	mlx_put_image_to_window(mlx, win, img3, 64, 0);
// 	mlx_put_image_to_window(mlx, win, img, 64, 32);
// 	mlx_put_image_to_window(mlx, win, img4, 64, 32);
// 	mlx_put_image_to_window(mlx, win, img, 0, 32);
// 	mlx_put_image_to_window(mlx, win, img5, 0, 32);
// 	mlx_put_image_to_window(mlx, win, img, 32, 32);
// 	mlx_put_image_to_window(mlx, win, img6, 32, 32);
// 	mlx_loop(mlx);
// 	return (0);
// }

void map_read(char *filename, t_game *game)
{
	int fd;
	char *line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	game->hei = 0;
	game->wid = ft_strlen(line) - 1;
	game->str_line = ft_strdup_without_newline(line);
	free(line);
	while (line)
	{
		game->hei++;
		line = get_next_line(fd);
		if (line)
		{
			game->str_line = ft_strjoin_without_newline(game->str_line, line);
		}
	}
	close(fd);
	printf("%s\n", game->str_line);
}


