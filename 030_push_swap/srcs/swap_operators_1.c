/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operators_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:46:42 by majacqua          #+#    #+#             */
/*   Updated: 2021/11/27 12:14:22 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_swap_one(t_lstack **stack)
{
	t_lstack	*second;
	t_lstack	*first;

	first = *stack;
	if (!stack || !first || !first->next)
		return ;
	else
	{
		second = first->next;
		if (!second->next)
			first->next = 0;
		else
		{
			second->next->prev = first;
			first->next = second->next;
		}
		second->next = first;
		second->prev = 0;
		first->prev = second;
		*stack = second;
	}
	printf("swap\n");
}

void	op_swap_two(t_lstack **stack1, t_lstack **stack2)
{
	op_swap_one(stack1);
	op_swap_one(stack2);
}

void	op_push(t_lstack **stack1, t_lstack **stack2)
{
	t_lstack	*list;
	t_lstack	*second;

	if (!stack1 || !*stack1)
		return ;
	else
	{
		list = *stack1;
		*stack1 = list->next;
		if (list->next)
			list->next->prev = 0;
		if (*stack2)
		{
			second = *stack2;
			second->prev = list;
			list->next = *stack2;
		}
		else
			list->next = 0;
		*stack2 = list;
		list->flag += 1;
	}
	printf("push\n");
}
