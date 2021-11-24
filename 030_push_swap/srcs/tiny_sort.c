/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:20:26 by majacqua          #+#    #+#             */
/*   Updated: 2021/11/24 15:20:10 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_lstack **stack)
{
	t_lstack	*first;
	t_lstack	*second;
	t_lstack	*third;

	first = *stack;
	second = first->next;
	third = second->next;
	if (first->value > second->value && first->value > third->value)
	{
		op_reverse_rotate_one(stack);
		if (second->value > third->value)
			op_swap_one(stack);
		return ;
	}
	else if (first->value < second->value && second->value > third->value)
	{
		op_swap_one(stack);
		op_reverse_rotate_one(stack);
	}
	else if (first->value < second->value && second->value > third->value)
		op_reverse_rotate_one(stack);
	else if (first->value > second->value && first->value < third->value)
		op_swap_one(stack);
	return ;
}

void	tiny_sort(t_lstack **stack1, t_lstack **stack2)
{
	sort_three(stack1);
	return ;
}
