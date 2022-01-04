/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/03 22:28:58 by oswin         #+#    #+#                 */
/*   Updated: 2022/01/03 22:41:05 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "so_long.h"

// void	push_black(t_data data)
// {
// 	int		x;
// 	int		y;
//
// 	new image
//
// 	x = 0;
// 	while (x < data.map.len * 64)
// 	{
// 		y = 0;
// 		while (y < data.map.dep * 64)
// 		{
//
// 			set this pixel in image to black
// 			y++;
// 		}
// 		x++;
// 	}
// 	push image
// }

void	sl_walk_up(t_data *data)
{
	if (data->map.map[data->y - 1][data->x] == '1')
		return ;
	if (data->map.map[data->y - 1][data->x] == 'E')
	{
		exit(0);
		mlx_destroy_window(data->mlx, data->win);
		return ;
	}
	data->map.map[data->y][data->x] = '0';
	data->map.map[data->y - 1][data->x] = 'P';
	// data->y--;
	// push_black(data);
	// mlx_clear_window(data->mlx, data->win);
	// push_map(*data);
	push_img_to_coords(*data, data->open, data->x, data->y);
	push_img_to_coords(*data, data->sprite, data->x, data->y - 1);
	data->y--;
	return ;
}
