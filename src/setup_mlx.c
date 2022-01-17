/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup_mlx.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/22 20:40:34 by oswin         #+#    #+#                 */
/*   Updated: 2022/01/17 10:38:58 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	setup_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (-8);
	data->win = mlx_new_window(data->mlx, data->map.len * 64,
			data->map.dep * 64, "Dolphin Game");
	if (data->win == NULL)
	{
		free(data->mlx);
		return (-8);
	}
	return (load_textures(data));
}
