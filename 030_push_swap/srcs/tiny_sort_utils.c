/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:39:41 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/06 14:55:17 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_stack_a(t_env *env)
{
	t_lstack	*first;
	t_lstack	*second;
	t_lstack	*third;

	first = *env->stack_a;
	second = first->next;
	third = second->next;
	if (first->value > second->value && first->value > third->value)
	{
		oper_ra(env);
		if (second->value > third->value)
			oper_sa(env);
		return ;
	}
	else if (first->value < third->value && second->value > third->value)
	{
		oper_sa(env);
		oper_ra(env);
	}
	else if (first->value < second->value && second->value > third->value)
		oper_rra(env);
	else if (first->value > second->value && first->value < third->value)
		oper_sa(env);
	return ;
}

void	sort_three_stack_b(t_env *env)
{
	t_lstack	*first;
	t_lstack	*second;
	t_lstack	*third;

	first = *env->stack_b;
	second = first->next;
	third = second->next;
	if (first->value > second->value && first->value > third->value)
	{
		oper_rb(env);
		if (second->value > third->value)
			oper_sb(env);
		return ;
	}
	else if (first->value < third->value && second->value > third->value)
	{
		oper_sb(env);
		oper_rb(env);
	}
	else if (first->value < second->value && second->value > third->value)
		oper_rrb(env);
	else if (first->value > second->value && first->value < third->value)
		oper_sb(env);
	return ;
}

void	sort_two(t_env *env, int stack_num)
{
	t_lstack	*first;
	t_lstack	*second;

	if (!stack_num)
		first = *env->stack_a;
	else
		first = *env->stack_b;
	if (!first->next)
		return ;
	second = first->next;
	if (first->value > second->value && !stack_num)
		oper_sa(env);
	else if (first->value > second->value && stack_num)
		oper_sb(env);
}

void	merge_two_sorted_stacks(t_env *env)
{
	size_t		i;
	size_t		len_stack1;
	t_lstack	*lowest_b;
	t_lstack	*iter_a;

	i = 0;
	iter_a = *env->stack_a;
	lowest_b = *env->stack_b;
	len_stack1 = ft_lstack_len(env->stack_a);
	while (i++ < len_stack1)
	{
		if (lowest_b && lowest_b->value <= iter_a->value)
		{	
			oper_pb(env);
			len_stack1++;
			if (ft_lstack_len(env->stack_b) != 0)
				lowest_b = *env->stack_b;
			else
				lowest_b = 0;
		}
		if (!is_sorted(env->stack_a))
			return ;
		oper_ra(env);
		iter_a = *env->stack_a;
	}	
}

void	sort_four_to_six(t_env *env)
{
	size_t		i;
	size_t		len_stack1;

	i = 0;
	len_stack1 = ft_lstack_len(env->stack_a);
	while (i < len_stack1 - 3)
	{
		oper_pa(env);
		i++;
	}
	if (i <= 2)
		sort_two(env, 1);
	else
		sort_three_stack_b(env);
	sort_three_stack_a(env);
	merge_two_sorted_stacks(env);
	while (ft_lstack_len(env->stack_b))
	{
		oper_pb(env);
		oper_ra(env);
	}	
}
