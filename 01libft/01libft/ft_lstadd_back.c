/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:01:26 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/08 17:29:03 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*iter;

	if (*lst == 0)
	{
		iter = new;
		*lst = new;
		return ;
	}
	iter = *lst;
	while (iter)
	{
		if (iter->next == 0)
		{
			iter->next = new;
			return ;
		}
		iter = iter->next;
	}
}
