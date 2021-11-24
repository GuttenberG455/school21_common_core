/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operators_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:19:35 by majacqua          #+#    #+#             */
/*   Updated: 2021/11/24 12:36:50 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_rotate_one(t_lstack **stack)
{	
	t_lstack	*last;
	t_lstack	*first;

	if (!stack || !*stack)
		return ;
	else
	{
		first = *stack;
		if (!first->next)
			return ;
		last = ft_last_lstack(stack);
		if (last)
		{
			last->next = first;
			first->prev = last;
			*stack = first->next;
			first->next->prev = 0;
			first->next = 0;
		}		
	}
}

void	op_rotate_two(t_lstack **stack1, t_lstack **stack2)
{
	op_rotate_one(stack1);
	op_rotate_one(stack2);
}

void	op_reverse_rotate_one(t_lstack **stack)
{
	t_lstack	*last;
	t_lstack	*first;

	if (!stack || !*stack)
		return ;
	else
	{
		first = *stack;
		if (!first->next)
			return ;
		last = ft_last_lstack(stack);
		if (last)
		{
			last->prev->next = 0;
			last->next = first;
			first->prev = last;
			*stack = last;
			last->prev = 0;
		}		
	}
}

void	op_reverse_rotate_two(t_lstack **stack1, t_lstack **stack2)
{
	op_reverse_rotate_one(stack1);
	op_reverse_rotate_one(stack2);
}
