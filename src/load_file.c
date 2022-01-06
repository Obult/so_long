#include "libft.h"


char	**get_file_in_array(int fd, int *err)
{
	int		i;
	char	**map;

	map = ft_calloc(16, sizeof(char **));
	if (map == NULL)
	{
		err = -4;
		return (0);

	while (get_next_line(fd, &map[i]) != -1)
	{
		if (map[i][0] == '\0')
		{
			map[i] = 0;
			dep = i;
			return (map);
		}
		if ((i + 1) % 16 == 0)
		{
			tmp = ft_calloc((i + 1) + 16, sizeof(char **));
			if (tmp == NULL)
			{
				*err = -5;
				return (map);
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

