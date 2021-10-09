/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:05:22 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/09 12:15:36 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_statlstdelone(t_list *lst, void (*del)(void*))
{
	(*del)(lst->content);
	free(lst);
	lst = 0;
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	temp = 0;
	if (lst)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			ft_statlstdelone(*lst, del);
			(*lst) = temp;
		}
	}
	*lst = temp;
}
