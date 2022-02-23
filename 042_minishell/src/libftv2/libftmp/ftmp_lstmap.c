/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmp_lstmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:33:02 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/23 14:36:00 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmp.h"

t_list	*ftmp_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	**rett;

	if (!lst)
		return (NULL);
	rett = &ret;
	ret = NULL;
	while (lst)
	{
		ft_lstadd_back(rett, ftmp_lstnew((*f)(lst->data)));
		if (!ft_lstlast(*rett))
		{
			ft_lstclear(rett, del);
			ret = NULL;
			return (ret);
		}
		lst = lst->next;
	}
	return (*rett);
}
