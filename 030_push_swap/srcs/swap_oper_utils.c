/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_oper_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:46:42 by majacqua          #+#    #+#             */
/*   Updated: 2021/11/30 16:45:02 by majacqua         ###   ########.fr       */
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
}

void	op_push(t_lstack **stack1, t_lstack **stack2, int to_b, t_env *env)
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
		if (to_b)
			list->flag = env->flag;
	}
}

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
