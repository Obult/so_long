/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 22:21:45 by obult         #+#    #+#                 */
/*   Updated: 2021/12/12 17:41:17 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*temp;

	len = ft_strlen(s);
	temp = malloc((len + 1) * sizeof(char));
	if (!temp)
		return (temp);
	temp[len] = 0;
	return (ft_memcpy(temp, s, len));
}
