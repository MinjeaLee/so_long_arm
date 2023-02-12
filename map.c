#include "so_long.h"

int file_open(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error_file_maps\n", 2);
		exit(1);
	}
	return (fd);
}

map* parser(char *filename)
{
	map *m;
	char *tmp;
	int fd;

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
		m->height++;
		tmp = get_next_line(fd);
	}

	free(tmp);

	return (m);
}