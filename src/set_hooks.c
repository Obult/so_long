/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_hooks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/22 21:37:23 by oswin         #+#    #+#                 */
/*   Updated: 2022/01/20 12:18:34 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307 || keycode == 'q' || keycode == 53)
		exit(0);
	else if (keycode == 65362 || keycode == 119 || keycode == 13)
		sl_walk_up(data);
	else if (keycode == 65361 || keycode == 97 || keycode == 0)
		sl_walk_left(data);
	else if (keycode == 65364 || keycode == 115 || keycode == 1)
		sl_walk_down(data);
	else if (keycode == 65363 || keycode == 100 || keycode == 2)
		sl_walk_right(data);
	return (0);
}

int	set_hooks(t_data *data)
{
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 17, 0L, ft_close, data);
	return (0);
}
