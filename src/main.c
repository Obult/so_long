#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <unistd.h>
#include "so_long.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	t_data	data;

	data.error = import_map(&data, argc, argv);
		// 	setup_mlx(brrr);
		// 		load_textures()	
		// 			set_hooks()
	// catch_error()
	// loop_mlxie()
	add_printarray_fd(data.map.map, 1);

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