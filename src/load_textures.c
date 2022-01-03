/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_textures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/22 20:38:22 by oswin         #+#    #+#                 */
/*   Updated: 2022/01/03 15:14:36 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include <stddef.h>
#include <stdlib.h>

int	load_single_texture(t_image *img, void *mlx, char *location, int *error)
{
	img->ptr = mlx_xpm_file_to_image(mlx, location, &(img->width), &(img->height));
	if (img->ptr == NULL)
	{
		*error = -16;
		return (0);
	}
	return (1);
}


// I feel recursion is comming!
int	load_textures(t_data *data)
{
	if (load_single_texture(&data->wall, data->mlx, "textures/walls.xpm", &data->error))
	{
		if (load_single_texture(&data->open, data->mlx, "textures/open.xpm", &data->error))
		{
			if (load_single_texture(&data->exit, data->mlx, "textures/exit.xpm", &data->error))
			{
				if (load_single_texture(&data->food, data->mlx, "textures/food.xpm", &data->error))
				{
					load_single_texture(&data->sprite, data->mlx, "textures/sprite.xpm", &data->error);
					if (data->error)
						free(data->sprite.ptr);
				}
				if (data->error)
					free(data->food.ptr);
			}
			if (data->error)
				free(data->exit.ptr);
		}
		if (data->error)
			free(data->open.ptr);
	}
	if (data->error)
		return (-16);
	return (set_hooks(data));
}
