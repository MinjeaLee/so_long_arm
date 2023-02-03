/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 06:52:02 by mi                #+#    #+#             */
/*   Updated: 2023/02/02 01:23:28 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx_arm/mlx.h"
# include "./libft/libft.h"

typedef struct Image
{
	void *door_open;
	void *door_closed;
	void *food;
	void *player;
	void *wall;
	void *land;
} image;

typedef struct s_game
{
	void *mlx;
	void *win;
	image img;
	int wid;
	int hei;
	char *str_line;
	int all_col;
	int col_cnt;
	int walk_cnt;
} t_game;

#endif

