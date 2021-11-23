/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:24:07 by majacqua          #+#    #+#             */
/*   Updated: 2021/11/23 18:54:15 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lstack	*ft_create_list(int value)
{
	t_lstack	*ptr;

	ptr = (t_lstack *)malloc(sizeof(t_lstack));
	if (!(ptr))
		return (0);
	ptr->value = value;
	ptr->order = 0;
	ptr->flag = 0;
	ptr->prev = 0;
	ptr->next = 0;
	return (ptr);
}

void	ft_print_list(t_lstack **lst)
{
	t_lstack	*iter;

	if (!lst)
		return ;
	iter = *lst;
	while (iter)
	{
		// ft_putnbr_fd(lst->value, 1);
		// ft_putchar_fd('\n', 1);
		printf("%p %d -value |%d| next-%p prev-%p\n", iter, iter->value, iter->order, iter->next, iter->prev);
		iter = iter->next;
	}
}

void	ft_push_list(t_lstack **lst, t_lstack *new)
{
	t_lstack	*iter;
	static int	order = 0;

	if (*lst == 0)
	{
		iter = new;
		*lst = new;
		new->order = order++;
		return ;
	}
	iter = *lst;
	while (iter)
	{
		if (iter->next == 0)
		{
			iter->next = new;
			new->order = order++;
			new->prev = iter;
			return ;
		}
		iter = iter->next;
	}
}
