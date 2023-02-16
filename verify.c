// Verify that a valid path exists in the map
// The Player must be able to obtain C present on the map and go to E.
// using the four cardinal directions (N, S, E, W)
//
#include "so_long.h"

char **duplicate(game *g)
{
	char **map_temp;
	int i;
	int j;

	i = 0;
	map_temp = (char **)malloc(sizeof(char *) * g->m->height);
	while (i < g->m->height)
	{
		j = 0;
		map_temp[i] = (char *)malloc(sizeof(char) * ft_strlen(g->m->world[0]));
		while (j < ft_strlen(g->m->world[0]))
		{
			map_temp[i][j] = g->m->world[i][j];
			j++;
		}
		i++;
	}
	return (map_temp);
}

int dfs_e(int x, int y, char **map)
{
	int count;

	if (map[x][y] == '1')
		return (0);
	if (map[x][y] != 'V') // 방문처리('V)한 노드가 아니라면
	{
		if (map[x][y] == 'E')
		{
			map[x][y] = 'V'; // 'V'로 노드를 방문처리를 하였다.
			return (1);
		}
		map[x][y] = 'V';
		count = 0;
		count += dfs_e(x - 1, y, map); // 위,아래, 양옆으로 나아간다.
		count += dfs_e(x, y + 1, map);
		count += dfs_e(x + 1, y, map);
		count += dfs_e(x, y - 1, map);
		return (count);
	}
	return (0);
}

int dfs_c(int x, int y, char **map)
{
	int count;

	if (map[x][y] == '1' || map[x][y] == 'E')
		return (0);
	if (map[x][y] != 'V') // 방문처리('V)한 노드가 아니라면
	{
		if (map[x][y] == 'C')
		{
			map[x][y] = 'V'; // 'V'로 노드를 방문처리를 하였다.
			return (1);
		}
		map[x][y] = 'V';
		count = 0;
		count += dfs_c(x - 1, y, map); // 위,아래, 양옆으로 나아간다.
		count += dfs_c(x, y + 1, map);
		count += dfs_c(x + 1, y, map);
		count += dfs_c(x, y - 1, map);
		return (count);
	}
	return (0);
}

int has_valid_path(game *g)
{
	char **map_temp_c;
	char **map_temp_e;

	map_temp_c = duplicate(g); // duplicate는 이차원 배열들의 값을 복사하는 함수
	map_temp_e = duplicate(g);

	int c_count = dfs_c(g->p->x, g->p->y, map_temp_c);
	int e_count = dfs_e(g->p->x, g->p->y, map_temp_e);
	if (c_count != g->p->keys)
		return (0); // 플레이어가 수집할 수 있는 수집품 개수가 전체 수집품 개수와 다르면 false
	if (e_count != 1)
		return (0); // 탈출구 개수가 1이 아니면 false
	//TODO : duplicate 맵 free
	return (1);
}


