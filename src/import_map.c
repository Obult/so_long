/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   import_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/22 20:32:41 by oswin         #+#    #+#                 */
/*   Updated: 2022/01/17 10:36:40 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int	i;
	int	j;
	int	p;

	p = -1;
	i = 0;
	while (i < world->len)
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
	data->map.map = get_file_in_array(argv[1], &data->error);
	if (data->error < 0)
		return (data->error);
	if (check_map(&data->map) != 0)
		return (-6);
	data->map.len = ft_strlen(data->map.map[0]);
	return (setup_mlx(data));
}
