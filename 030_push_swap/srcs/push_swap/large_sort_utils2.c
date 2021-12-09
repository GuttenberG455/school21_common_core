/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:30:02 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/08 15:36:34 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_min_flag(t_lstack **stack)
{
	t_lstack	*iter;
	t_lstack	*min_iter;
	int			min_flag;

	iter = *stack;
	min_flag = INT_MAX;
	while (iter)
	{
		if (iter->flag < min_flag)
		{
			min_iter = iter;
			min_flag = iter->flag;
		}
		iter = iter->next;
	}
	return (min_iter->value);
}

void	rotate_for_push_alone(t_env *env, int steps_a, int steps_b)
{
	int	i;

	i = 0;
	if (steps_b > 0)
	{
		while (i++ < ft_abs(steps_b))
			oper_rb(env);
	}
	else if (steps_b < 0)
	{
		while (i++ < ft_abs(steps_b))
			oper_rrb(env);
	}
	i = 0;
	if (steps_a > 0)
	{
		while (i++ < ft_abs(steps_a))
			oper_ra(env);
	}
	else if (steps_a < 0)
	{
		while (i++ < ft_abs(steps_a))
			oper_rra(env);
	}	
}

void	rotate_for_push_both(t_env *env, int steps_a, int steps_b)
{
	int	new_steps_a;
	int	new_steps_b;

	new_steps_a = steps_a;
	new_steps_b = steps_b;
	while (ft_abs(new_steps_a) && ft_abs(new_steps_b))
	{
		if (steps_a > 0)
		{
			oper_rr(env);
			new_steps_a--;
			new_steps_b--;
		}
		else
		{
			oper_rrr(env);
			new_steps_a++;
			new_steps_b++;
		}
	}
	rotate_for_push_alone(env, new_steps_a, new_steps_b);
}

void	large_push_min_flag(t_env *env)
{
	int	steps_a;
	int	steps_b;

	steps_b = count_steps_to_top(env->stack_b, find_min_flag(env->stack_b));
	steps_a = count_steps_to_top(env->stack_a, find_closest_big(env->stack_a,
				find_min_flag(env->stack_b)));
	if (ft_same_sign(steps_a, steps_b))
		rotate_for_push_both(env, steps_a, steps_b);
	else
		rotate_for_push_alone(env, steps_a, steps_b);
	oper_pa(env);
	return ;
}
