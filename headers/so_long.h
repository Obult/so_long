/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/20 22:21:53 by oswin         #+#    #+#                 */
/*   Updated: 2022/01/10 22:16:08 by oswin         ########   odam.nl         */
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
	t_map	map;
	t_image	wall;
	t_image	open;
	t_image	exit;
	t_image	food;
	t_image	sprite;
  t_image jump0;
  t_image jump1;
  t_image jump2;
  t_image jump3;
  t_image jump4;
	int		error;
	int		x;
	int		y;
}			t_data;

int	import_map(t_data *data, int argc, char **argv);
t_map	get_map(char *location);

int	setup_mlx(t_data *data);

int	load_textures(t_data *data);

int	set_hooks(t_data *data);

void	push_img_to_coords(t_data data, t_image img, int x, int y);
void	push_map(t_data data);

void	sl_walk_up(t_data *data);
void	sl_walk_down(t_data *data);
void	sl_walk_left(t_data *data);
void	sl_walk_right(t_data *data);

char	**gnl_returner(int fd, char **map, int *err);
char	**get_file_in_array(char *loca, int *err);

#endif
