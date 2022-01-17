/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gnl.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 19:33:06 by oswin         #+#    #+#                 */
/*   Updated: 2022/01/17 13:18:07 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strclen(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	os_cpy(char *dst, char *src, int c)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != (char)c)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (i);
}

static char	*ft_addington(char *og, char *add)
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc(ft_strclen(og, '\n') + ft_strclen(add, '\n') + 1);
	if (!temp)
	{
		free(og);
		return (0);
	}
	if (og)
	{
		i = os_cpy(temp, og, '\n');
		free(og);
	}
	os_cpy(&temp[i], add, '\n');
	return (temp);
}

static int	bufferfix(char *buff, int lenflag)
{
	char	*temp;

	temp = buff;
	if (!lenflag)
		buff[0] = 0;
	while (*temp != '\n' && *temp)
		temp++;
	if (*temp != '\n')
		return (0);
	os_cpy(buff, temp + 1, 0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int				len;
	static char		buff[BUFFER_SIZE + 1];

	if (!line || fd < 0)
		return (-1);
	*line = ft_addington(0, buff);
	if (!(*line))
		return (-1);
	if (bufferfix(buff, 1))
		return (1);
	len = read(fd, buff, BUFFER_SIZE);
	while (len > 0)
	{
		buff[len] = 0;
		*line = ft_addington(*line, buff);
		if (!(*line))
			return (-1);
		if (bufferfix(buff, 1))
			return (1);
		len = read(fd, buff, BUFFER_SIZE);
	}
	if (!len)
		return (bufferfix(buff, 0));
	return (-1);
}
