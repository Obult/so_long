/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_printarray.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/28 23:23:49 by oswin         #+#    #+#                 */
/*   Updated: 2021/10/27 16:18:37 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	add_printarray_fd(char **arr, int fd)
{
	int		i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		ft_putendl_fd(arr[i], fd);
		i++;
	}
}
