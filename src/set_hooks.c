/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_hooks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/22 21:37:23 by oswin         #+#    #+#                 */
/*   Updated: 2021/12/22 21:46:03 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	// do stuff with keykodes w a s d and a quit hook maybe esc or a combo
}

int	set_hooks(t_data *data)
{
	t_vars	vars;

	vars.mlx = data->mlx;
	vars.win = data->win;
	mlx_key_hook(vars.win, key_hook, &vars);
}