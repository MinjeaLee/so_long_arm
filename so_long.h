/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 06:52:02 by mi                #+#    #+#             */
/*   Updated: 2023/02/05 04:35:10 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx_arm/mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

typedef struct Image
{
	void *door_open;
	void *door_closed;
	void *food;
	void *player;
	void *wall;
	void *land;
} image;

typedef struct Map
{
	int height;
	int width;
	char **world;
} map;

typedef struct Game
{
	void *mlx;
	void *win;
	int cnt_key;
	int keys;
	map *m;
	image *img;
} game;

int file_open(char *filename);
map *parser(char *filename);
void game_init(game *g, char *filename);
image *img_init(void *mlx);
void put_img(game *g, int w, int h);
void render_map(game *g);

#endif

