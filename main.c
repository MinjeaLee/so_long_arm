#include "./mlx_arm/mlx.h"
#include "./libft/libft.h"
// #include "./gnl/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>



int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*file_name;
	// int		fd;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		return (0);
	}
	file_name = argv[1];
	file_name = ft_strdup("./maps/");
	file_name = ft_strjoin(file_name, argv[1]);
	printf("%s", file_name);

	// fd = open(file_name, O_RDONLY);

	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 300, 300, "mlx_test");
	mlx_loop(mlx_ptr);

	return (0);
}