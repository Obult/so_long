#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <unistd.h>
#include "so_long.h"
#include "libft.h"

void	ft_free_array(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
}

int	ft_catch_error(t_data data)
{
	if (data.error >= -4)
		return (data.error);
	if (data.error <= -5)
	{
		ft_free_array((void *)data.map.map);
		free(data.map.map);
	}
	if (data.error <= -16)
	{
		// free mlx stuff
		mlx_destroy_window(data.mlx, data.win);
		mlx_destroy_display(data.mlx);
		free(data.mlx);
	}
	return (data.error);
}

int		main(int argc, char **argv)
{
	t_data	data;

	data.error = 0;
	data.error = import_map(&data, argc, argv);
	if (data.error < 0)
	{
		printf("error: %i\n", data.error);
		ft_catch_error(data);
		return (1);
	}
	printf("depth: %i\n", data.map.dep);
	printf("length: %i\n", data.map.len);
	add_printarray_fd(data.map.map, 1);

	// loop_mlxie()
	// mlx_put_image_to_window(data.mlx, data.win, data.wall.ptr, 64, 64);
	// push_img_to_coords(data, data.wall, 1, 1);
	push_map(data);
	sleep(15);

	data.error = -42;
	ft_catch_error(data);
}

// int main(void)
// {
// 	t_image	imp;
// 	void	*mlx_ptr;
// 	void	*win_ptr;

// 	mlx_ptr = mlx_init();
// 	if (mlx_ptr == NULL)
// 		return (42);

// 	win_ptr = mlx_new_window(mlx_ptr, 256, 256, "My first window!");
// 	if (win_ptr == NULL)
// 	{
// 		free(win_ptr);
// 		return (42);
// 	}

// 	imp.path = ft_strdup("textures/wool.xpm");
// 	imp.ptr = mlx_xpm_file_to_image(mlx_ptr, imp.path, &imp.width, &imp.height);
// 	if (imp.ptr == NULL)
// 		printf("xmp fail\n");
// 	printf("w %i\nh %i\n", imp.width, imp.height);
// 	mlx_put_image_to_window(mlx_ptr, win_ptr, imp.ptr, 0, 0);
// 	mlx_put_image_to_window(mlx_ptr, win_ptr, imp.ptr, 128, 0); 

// 	sleep(2);

// 	mlx_destroy_window(mlx_ptr, win_ptr);
// 	mlx_destroy_display(mlx_ptr);
// 	free(mlx_ptr);
// }