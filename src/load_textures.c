/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_textures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/22 20:38:22 by oswin         #+#    #+#                 */
/*   Updated: 2022/01/17 10:37:31 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_single_tex(t_image *img, void *mlx, char *location, int *error)
{
	img->ptr = mlx_xpm_file_to_image(mlx, location, &(img->width),
			&(img->height));
	if (img->ptr == NULL)
		*error = -16;
}

int	load_textures(t_data *data)
{
	load_single_tex(&data->wall, data->mlx, "tex/walls.xpm", &data->error);
	load_single_tex(&data->open, data->mlx, "tex/open.xpm", &data->error);
	load_single_tex(&data->exit, data->mlx, "tex/exit.xpm", &data->error);
	load_single_tex(&data->food, data->mlx, "tex/food.xpm", &data->error);
	load_single_tex(&data->sprite, data->mlx,
		"tex/new/sprite.xpm", &data->error);
	if (data->error)
		exit(0);
	return (set_hooks(data));
}
