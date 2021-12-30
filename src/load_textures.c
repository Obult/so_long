/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_textures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/22 20:38:22 by oswin         #+#    #+#                 */
/*   Updated: 2021/12/22 21:37:09 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_single_texture(t_image *img, void *mlx, char *location, int *error)
{
	img->ptr = mlx_xpm_file_to_image(mlx, location, &(img->width), &(img->height));
	if (img->ptr == NULL)
	{
		*error = 1;
		return (0);
	}
	return (1);
}

int	load_textures(t_data *data)
{
	if (load_single_texture(data->wall, data->mlx, "textures/wall.xpm", *data->error))
	{
		if (load_single_texture(data->open, data->mlx, "textures/open.xpm", *data->error))
		{
			if (load_single_texture(data->exit, data->mlx, "textures/exit.xpm", *data->error))
			{
				if (load_single_texture(data->food, data->mlx, "textures/food.xpm", *data->error))
				{
					load_single_texture(data->sprite, data->mlx, "textures/sprite.xpm", *data->error);
					if (data->error)
						free(data->sprite.ptr)
				}
				if (data->error)
					free(data->food.ptr)
			}
			if (data->error)
				free(data->exit.ptr)
		}
		if (data->error)
			free(data->open.ptr)
	}
	if (data->error)
		return (-43);
	return (set_hooks(data));
}
