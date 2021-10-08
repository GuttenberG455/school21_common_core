/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:38:27 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/08 16:03:37 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*ptr;
	t_list	*temp;

	ptr = 0;
	temp = *lst;
	if (!(lst))
		*lst = new;
	else
	{
		ptr = new;
		ptr->next = temp;
	}
	*lst = ptr;
}
