#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


char	*rev_str(char *str)
{
	int		len;
	char	*rev_str;
	int		i;


	len = ft_strlen(str);
	rev_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!rev_str)
		return (NULL);

	rev_str[len] = '\0';
	i = 0;
	while (i < len)
	{
		rev_str[i] = str[len - i - 1];
		i++;
	}

	return (rev_str);
}

char	*initializer(int argc, char *file_name)
{
	char	*new_file_name;
	char	*rev_file_name;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		exit(1);
	}
	rev_file_name = rev_str(file_name);
	if (ft_strncmp(rev_file_name, "reb.", 4) != 0)
	{
		ft_putstr_fd("Error: Wrong file extension\n", 2);
		exit(1);
	}
	free(rev_file_name);

	new_file_name = ft_strdup("./maps/");
	new_file_name = ft_strjoin(new_file_name, file_name);

	return (new_file_name);
}

void	map_rule_check(char **map, int height)
{
	int 		len;
	int 		i;

	len = ft_strlen(*map);
	i = 0;
	while (map[i])
	{
		if (len != ft_strlen(map[i]) && i != height - 1)
		{
			ft_putstr_fd("Error: Map is not rectangular\n", 2);
			exit(1);
		}
		if (height - 1 == i && len - 1 != ft_strlen(map[i]))
		{
			ft_putstr_fd("Error: Map is not rectangular\n", 2);
			exit(1);
		}
		i++;
	}
}

char **map_parser(int fd)
{
	char	**map;
	int		len;
	int 	i;

	map = (char **)malloc(sizeof(char *) * 1);
	if (!map)
		return (NULL);
	i = 0;
	while ((map[i] = get_next_line(fd)) != NULL)
	{
		map = (char **)ft_realloc(map, sizeof(char *) * (i + 1));
		if (!map)
			return (NULL);
		i++;
	}
	map[i] = NULL;
	map_rule_check(map, i);

	return (map);
}

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	// char	*file_name;
	int		fd;


	fd = open(initializer(argc, argv[1]), O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: Failed to open file\n", 2);
		exit(1);
	}
	map_parser(fd);


	
	// mlx_ptr = mlx_init();
	// win_ptr = mlx_new_window(mlx_ptr, 300, 300, "mlx_test");
	
	// mlx_loop(mlx_ptr);

	return (0);
}