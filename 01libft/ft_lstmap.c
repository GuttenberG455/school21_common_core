/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:43:58 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/08 20:06:33 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*new;

	ptr = 0;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			while (ptr)
			{
				new = ptr->next;
				(*del)(ptr->content);
				free(ptr);
				ptr = new;
			}
			lst = 0;
			return (0);
		}
		ft_lstadd_back(&ptr, new);
		lst = lst->next;
	}
	return (ptr);
}
