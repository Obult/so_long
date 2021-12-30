/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/20 22:21:53 by oswin         #+#    #+#                 */
/*   Updated: 2021/12/22 21:46:15 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct s_image
{
	void	*ptr;
	int		width;
	int		height;
}			t_image;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		**map; // maybe needs its own struct (probably) aand need width and height?
	t_image	wall;
	t_image	open;
	t_image	exit;
	t_image	food;
	t_image	sprite;
	int		error;
}			t_data;

#endif
