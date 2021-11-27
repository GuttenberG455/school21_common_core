/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:20:26 by majacqua          #+#    #+#             */
/*   Updated: 2021/11/27 16:39:28 by majacqua         ###   ########.fr       */
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
		op_rotate_one(stack);
		if (second->value > third->value)
			op_swap_one(stack);
		return ;
	}
	else if (first->value < third->value && second->value > third->value)
	{
		op_swap_one(stack);
		op_rotate_one(stack);
	}
	else if (first->value < second->value && second->value > third->value)
		op_reverse_rotate_one(stack);
	else if (first->value > second->value && first->value < third->value)
		op_swap_one(stack);
	return ;
}

void	sort_two(t_lstack **stack)
{
	t_lstack	*first;
	t_lstack	*second;

	first = *stack;
	if (!first->next)
		return ;
	second = first->next;
	if (first->value > second->value)
		op_swap_one(stack);
}

void	merge_two_sorted_stacks(t_lstack **stack1, t_lstack **stack2)
{
	size_t		i;
	size_t		len_stack1;
	t_lstack	*lowest_b;
	t_lstack	*iter_a;

	i = 0;
	iter_a = *stack1;
	lowest_b = *stack2;
	len_stack1 = ft_lstack_len(stack1);
	while (i < len_stack1)
	{
		if (lowest_b && lowest_b->value <= iter_a->value)
		{	
			op_push(stack2, stack1);
			len_stack1++;
			if (ft_lstack_len(stack2) != 0)
				lowest_b = *stack2;
			else
				lowest_b = 0;
		}
		op_rotate_one(stack1);
		iter_a = *stack1;
		i++;
	}	
}

void	sort_four_to_six(t_env *env)
{
	size_t		i;
	size_t		len_stack1;
	t_lstack	*lowest_b;
	t_lstack	*iter_a;

	i = 0;
	len_stack1 = ft_lstack_len(env->stack_a);
	while (i < len_stack1 - 3)
	{
		op_push(env->stack_a, env->stack_b);
		i++;
	}
	if (i <= 2)
		sort_two(env->stack_b);
	else
		sort_three(env->stack_b);
	sort_three(env->stack_a);
	merge_two_sorted_stacks(env->stack_a, env->stack_b);
	while (ft_lstack_len(env->stack_b))
	{
		op_push(env->stack_b, env->stack_a);
		op_rotate_one(env->stack_a);
	}	
}

void	tiny_sort(t_env *env)
{	
	if (ft_lstack_len(env->stack_a) <= 2)
		sort_two(env->stack_a);
	else if (ft_lstack_len(env->stack_a) == 3)
		sort_three(env->stack_a);
	else if (ft_lstack_len(env->stack_a) >= 4)
		sort_four_to_six(env);
}
