/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   import_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/22 20:32:41 by oswin         #+#    #+#                 */
/*   Updated: 2022/01/02 21:56:56 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <stdlib.h>
#include <fcntl.h>

int	import_map(t_data *data, int argc, char **argv)
{
	if (argc != 2)
		return (-1);
	data->map = get_map(argv[1]);
	if (data->map.err < 0)
		return (data->map.err);
	// check_map(data->map); 
	return(0);

	// return (setup_mlx(data));
}

t_map	get_map(char *location)
{
	int		fd;
	int		i;
	char	**tmp;
	t_map	world;

	world.err = 0;
	i = 0;
	if (ft_strnstr(location, ".ber", -1) == NULL) // maybe needle ".ber\0"
	{
		world.err = -2;
		return (world);		
	}
	fd = open(location, O_RDONLY);
	if (fd == -1)
	{
		world.err = -3;
		return (world);		
	}
	world.map = malloc(16 * sizeof(char **));
	if (world.map == NULL)
	{
		world.err = -4;
		return (world);		
	}
	while (get_next_line(fd, &world.map[i]) != -1)
	{
		if (world.map[i] == NULL)
		{
			world.dep = i;
			return (world);
		}
		if ((i + 1) % 16 == 0)
		{
			tmp = malloc(((i + 1) + 16) * sizeof(char **));
			if (tmp == NULL)
			{
				world.err = -5;
				return (world);
			}
			ft_memcpy(tmp, world.map, i + 1);
			free(world.map);
			world.map = tmp;
		}
		i++;
	}
	world.err = -5;
	return (world);		

}

// int	check_map(t_map world)
// {
// 	int	line_length;
// 	int	
// }
