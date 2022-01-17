/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/10 22:34:19 by oswin         #+#    #+#                 */
/*   Updated: 2022/01/17 13:01:52 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_array(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
}

int	ft_catch_error(t_data data)
{
	if (data.error >= -4)
		return (data.error);
	if (data.error <= -5)
	{
		ft_free_array((void *)data.map.map);
		free(data.map.map);
	}
	if (data.error <= -16)
	{
		mlx_destroy_window(data.mlx, data.win);
		exit(0);
	}
	return (data.error);
}

void	check_state(t_data *data, int x, int y)
{
	if (data->map.map[y][x] == 'P')
	{
		data->x = x;
		data->y = y;
	}
	if (data->map.map[y][x] == 'E')
		data->e++;
	if (data->map.map[y][x] == 'C')
		data->c++;
}

void	set_startpoint(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	data->e = 0;
	data->c = 0;
	while (x < data->map.len)
	{
		y = 0;
		while (y < data->map.dep)
		{
			check_state(data, x, y);
			y++;
		}
		x++;
	}
	if (data->e == 0 || data->c == 0)
		data->error = -21;
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.error = 0;
	data.moves = 0;
	data.error = import_map(&data, argc, argv);
	if (data.error < 0)
	{
		ft_putendl_fd("Error", 2);
		ft_putnbr_fd(data.error, 2);
		ft_catch_error(data);
		return (1);
	}
	set_startpoint(&data);
	if (data.error < 0)
	{
		ft_putendl_fd("Error", 2);
		ft_putnbr_fd(data.error, 2);
		ft_catch_error(data);
		return (1);
	}
	push_map(data);
	mlx_loop(data.mlx);
}
