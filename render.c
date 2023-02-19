/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 23:04:36 by mi                #+#    #+#             */
/*   Updated: 2023/02/19 18:32:34 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*img_init(void *mlx)
{
	t_image	*img;
	int		w;
	int		h;

	img = (t_image *)malloc(sizeof(t_image));
	img->door_o = mlx_xpm_file_to_image(mlx, "./images/door_o.xpm", &w, &h);
	img->door_c = mlx_xpm_file_to_image(mlx, "./images/door_c.xpm", &w, &h);
	img->food = mlx_xpm_file_to_image(mlx, "./images/food.xpm", &w, &h);
	img->player = mlx_xpm_file_to_image(mlx, "./images/player.xpm", &w, &h);
	img->wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &w, &h);
	img->land = mlx_xpm_file_to_image(mlx, "./images/land.xpm", &w, &h);
	return (img);
}

void	put_img(t_game *g, int w, int h)
{
	mlx_put_image_to_window(g->mlx, g->win, g->img->land, w * 32, h * 32);
	if (g->m->world[h][w] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img->wall, w * 32, h * 32);
	else if (g->m->world[h][w] == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->img->player, w * 32, h * 32);
	else if (g->m->world[h][w] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->img->food, w * 32, h * 32);
	else if (g->m->world[h][w] == 'E' && g->p->keys == g->p->cnt_key)
		mlx_put_image_to_window(g->mlx, g->win, g->img->door_o, w * 32, h * 32);
	else if (g->m->world[h][w] == 'E' && g->p->keys != g->p->cnt_key)
		mlx_put_image_to_window(g->mlx, g->win, g->img->door_c, w * 32, h * 32);
	else
		mlx_put_image_to_window(g->mlx, g->win, g->img->land, w * 32, h * 32);
}

void	render_map(t_game *g)
{
	int	w;
	int	h;

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
