/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/20 22:21:53 by oswin         #+#    #+#                 */
/*   Updated: 2022/01/03 21:53:47 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_image
{
	void	*ptr;
	int		width;
	int		height;
}			t_image;

typedef struct s_map
{
	char	**map;
	int		len;
	int		dep;
	int		err;
}			t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_map	map; // needs change to world to not have map.map cases
	t_image	wall;
	t_image	open;
	t_image	exit;
	t_image	food;
	t_image	sprite;
	int		error;
}			t_data;

int	import_map(t_data *data, int argc, char **argv);
t_map	get_map(char *location);

int	setup_mlx(t_data *data);

int	load_textures(t_data *data);

int	set_hooks(t_data *data);

void	push_img_to_coords(t_data data, t_image img, int x, int y);
void	push_map(t_data data);

#endif
