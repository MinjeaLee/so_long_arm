/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 06:52:02 by mi                #+#    #+#             */
/*   Updated: 2023/02/19 18:34:38 by mi               ###   ########.fr       */
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

# define X_EVENT_KEY_EXIT 17
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct Image
{
	void	*door_o;
	void	*door_c;
	void	*food;
	void	*player;
	void	*wall;
	void	*land;
}t_image;

typedef struct Map
{
	int		height;
	int		width;
	char	**world;
}t_map;

typedef struct Player
{
	int	x;
	int	y;
	int	walk_count;
	int	cnt_key;
	int	keys;
}t_player;

typedef struct Game
{
	void		*mlx;
	void		*win;
	t_map		*m;
	t_image		*img;
	t_player	*p;
}t_game;

// main
void		init(t_game *g, char *filename);
int			key_press(int keycode, t_game *g);
void		print_error(char *str);

// map
t_map		*map_init(char *filename);
int			file_open(char *filename);
void		parser(char *filename, t_map *m);
void		map_boundary_check(t_map *m);
void		map_entity_check(t_map *m);
int			exit_game(t_game *g);

// keyboard
void		clear_game(t_game *g);
void		press_w(t_game *g, t_player *p);
void		press_a(t_game *g, t_player *p);
void		press_s(t_game *g, t_player *p);
void		press_d(t_game *g, t_player *p);

// render
t_image		*img_init(void *mlx);
void		put_img(t_game *g, int w, int h);
void		render_map(t_game *g);

// game
t_player	*game_init(t_game *g);
void		find_start(t_game *g, t_player *p);
void		count_keys(t_game *g, t_player *p);

// verify
char		**duplicate(t_game *g);
int			dfs_c(int x, int y, char **map);
int			dfs_e(int x, int y, char **map);
int			has_valid_path(t_game *g);

#endif
