/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup_mlx.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/22 20:40:34 by oswin         #+#    #+#                 */
/*   Updated: 2022/01/03 15:39:35 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include <stddef.h>
#include <stdlib.h>

int	setup_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (-8);
	data->win = mlx_new_window(data->mlx, data->map.len * 64, data->map.dep * 64, "My first window!");
	if (data->win == NULL)
	{
		free(data->mlx); // does this need to be close_mlx??
		return (-8);
	}
	return (load_textures(data));
}
