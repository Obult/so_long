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
#include "libft.h"
#include <mlx.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

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

// void	rec_load_textures(t_data *data, char **loca, t_image **imgs);
//
// int	load_textures(t_data *data)
// {
// 	char	*loca[6];
// 	t_image *imgs[6];
//
// 	imgs[0] = &(data->wall);
// 	imgs[1] = &(data->open);
// 	imgs[2] = &(data->exit);
// 	imgs[3] = &(data->food);
// 	imgs[4] = &(data->sprite);
// 	imgs[5] = NULL;
// 	loca[0] = ft_strdup("textures/walls.xpm");
// 	loca[1] = ft_strdup("textures/open.xpm");
// 	loca[2] = ft_strdup("textures/exit.xpm");
// 	loca[3] = ft_strdup("textures/food.xpm");
// 	loca[4] = ft_strdup("textures/sprite.xpm");
// 	loca[5] = NULL;
//
// 	rec_load_textures(data, loca, imgs);
// 	// exit(0);
// 	free(loca[0]);
// 	free(loca[1]);
// 	free(loca[2]);
// 	free(loca[3]);
// 	free(loca[4]);
// 	free(loca);
// 	free(imgs);
// 	return (data->error);
// }
//
// void	rec_load_textures(t_data *data, char **loca, t_image **imgs)
// {
// 	if (*loca == NULL)
// 		return ;
// 	load_single_texture(imgs[0], data->mlx, loca[0], &data->error);
// 	printf("error code: %i\n", data->error);
// 	if (data->error)
// 		return ;
// 	rec_load_textures(data, &(loca[1]), &(imgs[1]));
// 	if (data->error)
// 		free((*imgs)->ptr);
// }

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
	// load_single_texture(&data->blck, data->mlx, "textures/blck.xpm", &data->error);
	if (data->error)
		return (-16);
	return (set_hooks(data));
}
