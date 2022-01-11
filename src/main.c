/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/10 22:34:19 by oswin         #+#    #+#                 */
/*   Updated: 2022/01/10 22:34:41 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <unistd.h>
#include "so_long.h"
#include "libft.h"

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

int	main(int argc, char **argv)
{
	t_data	data;

	data.error = 0;
	data.error = import_map(&data, argc, argv);
	if (data.error < 0)
	{
		printf("error: %i\n", data.error);
		ft_catch_error(data);
		return (1);
	}
	data.x = 5;
	data.y = 6;
	push_map(data);
	mlx_loop(data.mlx);
}
