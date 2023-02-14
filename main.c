/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:41:01 by mi                #+#    #+#             */
/*   Updated: 2023/02/14 18:15:20 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	init(game *g, char *filename)
{
	int	w;
	int	h;

	g->mlx = mlx_init();
	g->img = img_init(g->mlx);
	g->m = parser(filename);
	g->p = game_init(g);
	w = g->m->width * 32;
	h = g->m->height * 32;
	g->win = mlx_new_window(g->mlx, w, h, "so_long");
	render_map(g);
}

int	key_press(int keycode, game *g)
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
	game	*g;

	g = (game *)malloc(sizeof(game));
	if (argc != 2)
		print_error("Error_argument\n");
	init(g, argv[1]);
	mlx_hook(g->win, X_EVENT_KEY_PRESS, 2, &key_press, g);
	mlx_loop(g->mlx);
	return (0);
}
