/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 06:52:02 by mi                #+#    #+#             */
/*   Updated: 2023/02/13 21:02:57 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx_arm/mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3

#define X_EVENT_KEY_EXIT 17
#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

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

typedef struct Player
{
	int x;
	int y;
	int walk_count;
} player;

typedef struct Game
{
	void *mlx;
	void *win;
	int cnt_key; // TODO : player로 옮기기
	int keys;
	map *m;
	image *img; 
	player *p;
} game;


// main
void init(game *g, char *filename);
int key_press(int keycode, game *g);
void print_error(char *str);

// map
int file_open(char *filename);
map *parser(char *filename);

// keyboard
int clear_game(game *g);
void press_w(game *g);
void press_a(game *g);
void press_s(game *g);
void press_d(game *g);

// render
image *img_init(void *mlx);
void put_img(game *g, int w, int h);
void render_map(game *g);

// game
player *game_init(game *g);
void find_start(game *g, player *p);
void count_keys(game *g, player *p);


#endif

