/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:44:01 by mi                #+#    #+#             */
/*   Updated: 2023/02/19 18:35:02 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*map_init(char *filename)
{
	t_map	*m;

	m = (t_map *)malloc(sizeof(t_map));
	parser(filename, m);
	map_boundary_check(m);
	map_entity_check(m);
	return (m);
}

int	file_open(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error("Unable to read file\n");
	return (fd);
}

void	parser(char *filename, t_map *m)
{
	char	*tmp;
	int		fd;
	int		h;

	fd = file_open(filename);
	m->world = (char **)malloc(sizeof(char *));
	tmp = ft_strip(get_next_line(fd));
	m->width = ft_strlen(tmp);
	m->height = 0;
	h = 0;
	while (tmp)
	{
		m->world = (char **)ft_realloc(m->world, sizeof(char *) * h + 1);
		*(m->world + m->height) = tmp;
		m->height++;
		tmp = ft_strip(get_next_line(fd));
		if (tmp == NULL)
			break ;
		if (ft_strlen(tmp) != m->width)
			print_error("Invalid map format\n");
		h++;
	}
	if ((m->height < 3 || m->width < 3) || (m->height == 3 && m->width == 3))
		print_error("It's not a big enough map.\n");
}

void	map_boundary_check(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < m->height)
	{
		while (j < m->width)
		{
			if (i == 0 || i == m->height - 1)
			{
				if (m->world[i][j] != '1')
					print_error("Invalid map format\n");
			}
			else
			{
				if (m->world[i][j] != '1' && (j == 0 || j == m->width - 1))
					print_error("Invalid map format\n");
			}
			j++;
		}
		j = 0;
		i++;
	}
}
	/*
	! 맵 테두리가 모두 1로 둘러 쌓여있는지 -> O
	! 맵이 직사각형인지
*/

void	map_entity_check(t_map *m)
{
	int	i;
	int	j;
	int	count_p;
	int	count_e;

	i = 0;
	j = 0;
	count_p = 0;
	count_e = 0;
	while (i < m->height)
	{
		while (j < m->width)
		{
			if (m->world[i][j] == 'P')
				count_p++;
			if (m->world[i][j] == 'E')
				count_e++;
			j++;
		}
		j = 0;
		i++;
	}
	if (count_e != 1 || count_p != 1)
		print_error("Insufficient entities\n");
}
/*
	! 맵에 엔터티 확인
	! 맵에 exit가 하나인지 -> O
	! 맵에 player가 하나인지 -> O


TODO: 맵 유효성 체크
! 1. 맵의 테두리가 모두 1로 둘러쌓여있는지 -> map_map_boundary_check
! 2. 맵의 가로 세로가 3이상인지, 하지만 여기서 가로 세로가 모두 3인 경우는 유효하지 x -> map_parser
! 3. 맵이 직사각형인지 -> map_parser

! 4. 맵에 엔터티 확인
! 4-1. 맵에 key가 하나 이상인지 -> game_count_key
! 4-2. 맵에 exit가 하나인지	-> map_map_entity_check
! 4-3. 맵에 player가 하나인지 -> map_map_entity_check

! 7. 맵에 유효한 경로가 있는지
*/
