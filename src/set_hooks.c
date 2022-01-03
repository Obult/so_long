/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_hooks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/22 21:37:23 by oswin         #+#    #+#                 */
/*   Updated: 2022/01/03 22:17:04 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include <stdlib.h>
#include "libft.h"
#include <unistd.h>

int	key_hook(int keycode, t_data *data)
{
	// ft_putnbr_fd(keycode, 1);
	// write(1, "\n", 1);
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	else if (keycode == 65362)
		sl_walk_up(data);
	else if (keycode == 65361)
		sl_walk_left(data);
	else if (keycode == 65364)
		sl_walk_down(data);
	else if (keycode == 65363)
		sl_walk_right(data);
	else if (keycode == 32)
		sl_do_special(data);
	return (0);
}

int	set_hooks(t_data *data)
{
	mlx_key_hook(data->win, key_hook, data);
	return (0);
}
