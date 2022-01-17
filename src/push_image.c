/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_image.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/03 14:54:17 by oswin         #+#    #+#                 */
/*   Updated: 2022/01/17 10:52:23 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	push_img_to_coords(t_data data, t_image img, int x, int y)
{
	mlx_put_image_to_window(data.mlx, data.win, img.ptr, x * 64, y * 64);
}

void	pick_image_to_push(t_data data, int x, int y)
{
	if (data.map.map[y][x] == '1')
		push_img_to_coords(data, data.wall, x, y);
	if (data.map.map[y][x] == '0')
		push_img_to_coords(data, data.open, x, y);
	if (data.map.map[y][x] == 'E')
		push_img_to_coords(data, data.exit, x, y);
	if (data.map.map[y][x] == 'C')
		push_img_to_coords(data, data.food, x, y);
	if (data.map.map[y][x] == 'P')
		push_img_to_coords(data, data.sprite, x, y);
}

void	push_map(t_data data)
{
	int		x;
	int		y;

	x = 0;
	while (x < data.map.len)
	{
		y = 0;
		while (y < data.map.dep)
		{
			pick_image_to_push(data, x, y);
			y++;
		}
		x++;
	}
}
