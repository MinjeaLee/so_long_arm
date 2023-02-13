/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:44:01 by mi                #+#    #+#             */
/*   Updated: 2023/02/13 21:32:29 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_open(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error("Error_file_open\n");
	return (fd);
}

map	*parser(char *filename)
{
	map		*m;
	char	*tmp;
	int		fd;

	m = (map *)malloc(sizeof(map));
	fd = file_open(filename);
	m->world = (char **)malloc(sizeof(char *));
	tmp = get_next_line(fd);
	m->width = ft_strlen(tmp) - 1;
	m->height = 0;
	while (tmp)
	{
		m->world = (char **)ft_realloc(m->world, sizeof(char *) * m->height + 1);
		*(m->world + m->height) = tmp;
		// free(tmp);
		m->height++;
		tmp = get_next_line(fd);
	}
	// free(tmp);
	if (m->height < 3 || m->width < 3)
		print_error("Error_map_size\n");
	if (m->height == 3 && m->width == 3)
		print_error("Error_map_size\n");
	return (m);
}

int map_boundary_check(map *m)
{
	//! 맵 테두리가 모두 1로 둘러 쌓여있는지
	//! 맵이 직사각형인지
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (i < m->height)
	{
		while (j < m->width)
		{
			if (i == 0 || i == m->height - 1)
			{
				if (m->world[i][j] != '1')
				return (0);
			}
			else
			{
				if (m->world[i][j] != '1' && (j == 0 || j == m->width - 1))
					return (0);
			}
			j++;	
		}
		j = 0;
		i++;
	}
	return (1);
}

int map_entity_check(map *m)
{
	//! 맵에 엔터티 확인
	//! 맵에 key가 하나 이상인지
	//! 맵에 exit가 하나인지
	//! 맵에 player가 하나인지
	int i;
	int j;
	int count_p;
	int count_e;

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
		return (0);
	return (1);
}
// TODO: 맵 유효성 체크
//! 1. 맵의 테두리가 모두 1로 둘러쌓여있는지
//! 2. 맵의 가로 세로가 3이상인지, 하지만 여기서 가로 세로가 모두 3인 경우는 유효하지 x
//! 3. 맵이 직사각형인지

//! 4. 맵에 엔터티 확인
//! 4-1. 맵에 key가 하나 이상인지
//! 4-2. 맵에 exit가 하나인지
//! 4-3. 맵에 player가 하나인지

//! 7. 맵에 유효한 경로가 있는지
