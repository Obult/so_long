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

void	sl_walk_up(t_data data)
{
	if (data.map.map[data.y - 1][data.x] == '1')
		return ;
	if (data.map.map[data.y - 1][data.x] == 'E')
	{
		exit(0);
		return ;
	}
	data.map.map[data.y][data.x] = '0';
	push_img_to_coords(data, data.open, data.x, data.y);
	push_img_to_coords(data, data.sprite, data.x, data.y - 1);
}