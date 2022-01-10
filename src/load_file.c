#include "libft.h"
#include "so_long.h"
#include <unistd.h>
#include <fcntl.h>

char	**get_file_in_array(char *loca, int *err)
{
	int		fd;
	char	**map;

	*err = 0;
	if (ft_strnstr(loca, ".ber", -1) == NULL)	// also needs work
	{
		*err = -2;
		return (NULL);
	}
	fd = open(loca, O_RDONLY);
	if (fd == -1)
	{
		*err = -3;
		return (NULL);
	}
	map = ft_calloc(16, sizeof(char **));
	if (map == NULL)
	{
		*err = -4;
		return (NULL);
	}
	return(gnl_returner(fd, map, err));
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**ft_array_extender(char ***arr, int now, int ext)
{
	char	**tmp;

	tmp = ft_calloc(now + ext, sizeof(char **));
	if (tmp == NULL)
	{
		free_map(*arr);
		return (tmp);
	}
	ft_memcpy(tmp, *arr, now);
	if (now != 0)
		free(*arr);
	*arr = tmp;
	return (*arr);
}

char	**gnl_returner(int fd, char **map, int *err)
{ 
	int	i;
	int	gnl;

	i = 0;
	gnl = 1;
	while (gnl != 0)
	{
		if ((i + 1) % 16 == 0)
		{
			if (ft_array_extender(&map, i, 16) == NULL) // here there are still problems
			{
				*err = -5;
				return (NULL);
			}
		}
		gnl = get_next_line(fd, &map[i]);
		if (gnl == -1)
		{
			free_map(map);
			*err = -5;
			return (NULL);
		}
		i++;
	}
	return (map);
}
