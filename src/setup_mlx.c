/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup_mlx.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/22 20:40:34 by oswin         #+#    #+#                 */
/*   Updated: 2021/12/22 21:20:43 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	setup_mlx(*data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (-42);
	data->win = mlx_new_window(mlx_ptr, 256, 256, "My first window!");
	if (data->win == NULL)
	{
		free(data->mlx);
		return (-42);
	}
	return (load_textures(data));
}
