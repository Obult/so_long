/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   import_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/22 20:32:41 by oswin         #+#    #+#                 */
/*   Updated: 2022/01/03 15:54:39 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	ft_arrlen(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	check_map_data(t_map *world)
{
	int i;
	int j;
	int	p;

	p = -1;
	i = 0;
	while (i <world->len)
	{
		j = 0;
		while (j < world->dep)
		{
			if (i == 0 || j == 0 || i == world->len -1 || j == world->dep - 1)
			{
				if (world->map[j][i] != '1')
					return (-6);
			}
			else if (ft_strrchr("10CPE", world->map[j][i]) == NULL)
				return (-6);
			if (world->map[j][i] == 'P')
				p++;
			j++;
		}
		i++;
	}
	return (p);
}

int	check_map(t_map *world)
{
	int	i;

	i = 0;
	world->len = ft_strlen(world->map[0]);
	if (world->len < 3)
		return (-6);
	world->dep = ft_arrlen((void *)world->map);
	if (world->dep < 3)
		return (-6);
	while (i < world->dep)
	{
		if ((int)ft_strlen(world->map[i]) != world->len)
			return (-6);
		i++;
	}
	return (check_map_data(world));
}

int	import_map(t_data *data, int argc, char **argv)
{
	if (argc != 2)
		return (-1);
	data->map = get_map(argv[1]);
	if (data->map.err < 0)
		return (data->map.err);

	if(check_map(&data->map) != 0) // here checking starts
		return (-6);
	data->map.len = ft_strlen(data->map.map[0]);

	return (setup_mlx(data));
}

t_map	get_map(char *location)
{
	int		fd;
	int		i;
	char	**tmp;
	t_map	world;

	world.err = 0;
	i = 0;
	if (ft_strnstr(location, ".ber", -1) == NULL)
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
	world.map = ft_calloc(16, sizeof(char **));
	if (world.map == NULL)
	{
		world.err = -4;
		return (world);
	}


	while (get_next_line(fd, &world.map[i]) != -1)
	{
		if (world.map[i][0] == '\0')
		{
			world.map[i] = 0;
			world.dep = i;
			return (world);
		}
		if ((i + 1) % 16 == 0)
		{
			tmp = ft_calloc((i + 1) + 16, sizeof(char **));
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
