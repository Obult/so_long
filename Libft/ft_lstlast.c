/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 15:07:48 by obult         #+#    #+#                 */
/*   Updated: 2021/12/12 17:37:17 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Returns the last element of the list.
*/

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst || !(lst->next))
		return (lst);
	return (ft_lstlast(lst->next));
}
