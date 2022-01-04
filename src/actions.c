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

void	push_black(t_data data)
{
	int		x;
	int		y;

	x = 0;
	while (x < data.map.len)
	{
		y = 0;
		while (y < data.map.dep)
		{
			// pick_image_to_push(data, x, y);
			push_img_to_coords(data, data.blck, x, y);
			y++;
		}
		x++;
	}
}

void	sl_walk_up(t_data data)
{
	if (data.map.map[data.y - 1][data.x] == '1')
		return ;
	if (data.map.map[data.y - 1][data.x] == 'E')
	{
		exit(0);
		mlx_destroy_window(data.mlx, data.win);
		return ;
	}
	data.map.map[data.y][data.x] = '0';
	data.map.map[data.y - 1][data.x] = 'P';
	data.y--;
	// push_black(data);
	push_map(data);
	// push_img_to_coords(data, data.open, data.x, data.y);
	// push_img_to_coords(data, data.sprite, data.x, data.y - 1);
	return ;
}
