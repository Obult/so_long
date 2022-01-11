/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_textures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/22 20:38:22 by oswin         #+#    #+#                 */
/*   Updated: 2022/01/10 22:33:37 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include <mlx.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void	load_single_tex(t_image *img, void *mlx, char *location, int *error)
{
	img->ptr = mlx_xpm_file_to_image(mlx, location, &(img->width),
			&(img->height));
	if (img->ptr == NULL)
		*error = -16;
}

void	destroy_texture(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	destructor_textures(t_data *data)
{
	destroy_texture(data->wall.ptr);
	destroy_texture(data->open.ptr);
	destroy_texture(data->exit.ptr);
	destroy_texture(data->food.ptr);
	destroy_texture(data->sprite.ptr);
	destroy_texture(data->jump0.ptr);
	destroy_texture(data->jump1.ptr);
	destroy_texture(data->jump2.ptr);
	destroy_texture(data->jump3.ptr);
	destroy_texture(data->jump4.ptr);
}

void	init_textures(t_data *data)
{
	data->wall.ptr = 0;
	data->open.ptr = 0;
	data->exit.ptr = 0;
	data->food.ptr = 0;
	data->sprite.ptr = 0;
	data->jump0.ptr = 0;
	data->jump1.ptr = 0;
	data->jump2.ptr = 0;
	data->jump3.ptr = 0;
	data->jump4.ptr = 0;
}

int	load_textures(t_data *data)
{
	init_textures(data);
	load_single_tex(&data->wall, data->mlx, "tex/walls.xpm", &data->error);
	load_single_tex(&data->open, data->mlx, "tex/open.xpm", &data->error);
	load_single_tex(&data->exit, data->mlx, "tex/exit.xpm", &data->error);
	load_single_tex(&data->food, data->mlx, "tex/food.xpm", &data->error);
	load_single_tex(&data->sprite, data->mlx, "tex/new/sprite.xpm", &data->error);
	load_single_tex(&data->jump0, data->mlx, "tex/new/jump0.xpm", &data->error);
	load_single_tex(&data->jump1, data->mlx, "tex/new/jump1.xpm", &data->error);
	load_single_tex(&data->jump2, data->mlx, "tex/new/jump2.xpm", &data->error);
	load_single_tex(&data->jump3, data->mlx, "tex/new/jump3.xpm", &data->error);
	load_single_tex(&data->jump4, data->mlx, "tex/new/jump4.xpm", &data->error);
	if (data->error)
	{
		destructor_textures(data);
		return (-16);
	}
	return (set_hooks(data));
}
