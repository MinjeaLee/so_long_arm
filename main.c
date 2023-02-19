/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:41:01 by mi                #+#    #+#             */
/*   Updated: 2023/02/19 18:32:34 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *str)
{
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}

int	exit_game(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	exit(0);
	return (0);
}

void	init(t_game *g, char *filename)
{
	int	w;
	int	h;

	g->mlx = mlx_init();
	g->img = img_init(g->mlx);
	g->m = map_init(filename);
	g->p = game_init(g);
	if (!has_valid_path(g))
		print_error("No valid path exists\n");
	w = g->m->width * 32;
	h = g->m->height * 32;
	g->win = mlx_new_window(g->mlx, w, h, "so_long");
	render_map(g);
}

int	key_press(int keycode, t_game *g)
{
	if (keycode == KEY_W)
		press_w(g, g->p);
	else if (keycode == KEY_A)
		press_a(g, g->p);
	else if (keycode == KEY_S)
		press_s(g, g->p);
	else if (keycode == KEY_D)
		press_d(g, g->p);
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*g;

	g = (t_game *)malloc(sizeof(t_game));
	if (argc != 2)
		print_error("usage : ./so_long <map>\n");
	init(g, argv[1]);
	mlx_hook(g->win, X_EVENT_KEY_PRESS, 2, &key_press, g);
	mlx_hook(g->win, X_EVENT_KEY_EXIT, 0, &exit_game, g);
	mlx_loop(g->mlx);
	return (0);
}
