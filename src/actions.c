/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/03 22:28:58 by oswin         #+#    #+#                 */
/*   Updated: 2022/01/17 11:16:22 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exitcheck(t_data data)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	x = 0;
	while (x < data.map.len)
	{
		y = 0;
		while (y < data.map.dep)
		{
			if (data.map.map[y][x] == 'C')
				count++;
			y++;
		}
		x++;
	}
	return (count);
}

void	sl_walk_up(t_data *data)
{
	if (data->map.map[data->y - 1][data->x] == '1')
		return ;
	data->moves++;
	ft_putnbr_fd(data->moves, 1);
	write(1, "\n", 1);
	if (data->map.map[data->y - 1][data->x] == 'E')
	{
		if (exitcheck(*data) > 0)
			return ;
		exit(0);
		mlx_destroy_window(data->mlx, data->win);
		return ;
	}
	data->map.map[data->y][data->x] = '0';
	push_img_to_coords(*data, data->open, data->x, data->y);
	push_img_to_coords(*data, data->sprite, data->x, data->y - 1);
	data->y--;
	data->map.map[data->y][data->x] = 'P';
	return ;
}

void	sl_walk_left(t_data *data)
{
	if (data->map.map[data->y][data->x - 1] == '1')
		return ;
	data->moves++;
	ft_putnbr_fd(data->moves, 1);
	write(1, "\n", 1);
	if (data->map.map[data->y][data->x - 1] == 'E')
	{
		if (exitcheck(*data) > 0)
			return ;
		exit(0);
		mlx_destroy_window(data->mlx, data->win);
		return ;
	}
	data->map.map[data->y][data->x] = '0';
	push_img_to_coords(*data, data->open, data->x, data->y);
	push_img_to_coords(*data, data->sprite, data->x - 1, data->y);
	data->x--;
	data->map.map[data->y][data->x] = 'P';
	return ;
}

void	sl_walk_right(t_data *data)
{
	if (data->map.map[data->y][data->x + 1] == '1')
		return ;
	data->moves++;
	ft_putnbr_fd(data->moves, 1);
	write(1, "\n", 1);
	if (data->map.map[data->y][data->x + 1] == 'E')
	{
		if (exitcheck(*data) > 0)
			return ;
		exit(0);
		mlx_destroy_window(data->mlx, data->win);
		return ;
	}
	data->map.map[data->y][data->x] = '0';
	push_img_to_coords(*data, data->open, data->x, data->y);
	push_img_to_coords(*data, data->sprite, data->x + 1, data->y);
	data->x++;
	data->map.map[data->y][data->x] = 'P';
	return ;
}

void	sl_walk_down(t_data *data)
{
	if (data->map.map[data->y + 1][data->x] == '1')
		return ;
	data->moves++;
	ft_putnbr_fd(data->moves, 1);
	write(1, "\n", 1);
	if (data->map.map[data->y + 1][data->x] == 'E')
	{
		if (exitcheck(*data) > 0)
			return ;
		exit(0);
		mlx_destroy_window(data->mlx, data->win);
		return ;
	}
	data->map.map[data->y][data->x] = '0';
	push_img_to_coords(*data, data->open, data->x, data->y);
	push_img_to_coords(*data, data->sprite, data->x, data->y + 1);
	data->y++;
	data->map.map[data->y][data->x] = 'P';
	return ;
}
