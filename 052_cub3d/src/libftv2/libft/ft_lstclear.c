/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 23:44:12 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/10/13 14:31:17 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*to_del;
	t_list	*curr_lst;

	if (!lst)
		return ;
	to_del = *lst;
	while (to_del)
	{
		curr_lst = to_del->next;
		ft_lstdelone(to_del, del);
		to_del = curr_lst;
	}
	*lst = to_del;
}
