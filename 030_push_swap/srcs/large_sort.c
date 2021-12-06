/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:24:51 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/06 14:55:59 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	large_push_mid(t_env *env)
{
	int	steps;
	int	i;

	steps = count_steps_to_top(env->stack_a, env->mid);
	i = 0;
	if (steps > 0)
	{
		while (i++ < ft_abs(steps))
			oper_ra(env);
	}
	else if (steps < 0)
	{
		while (i++ < ft_abs(steps))
			oper_rra(env);
	}
	oper_pa(env);
	return ;
}

void	large_push_all_2b(t_env *env)
{
	t_lstack	*iter;

	while (ft_lstack_len(env->stack_a) != 2)
	{
		iter = *env->stack_a;
		if (iter->value != env->min && iter->value != env->max)
		{
			oper_pa(env);
			if (iter->value > env->mid)
				oper_rb(env);
		}
		else
			oper_ra(env);
	}
}

void	large_last_rotate(t_env *env)
{
	int	steps;
	int	i;

	i = 0;
	steps = count_steps_to_top(env->stack_a, env->min);
	if (steps > 0)
	{
		while (i++ < ft_abs(steps))
			oper_ra(env);
	}
	else if (steps < 0)
	{
		while (i++ < ft_abs(steps))
			oper_rra(env);
	}
}

void	large_sort(t_env *env)
{
	large_push_mid(env);
	large_push_all_2b(env);
	while (ft_lstack_len(env->stack_b))
	{		
		large_count_flags(env);
		find_min_flag(env->stack_b);
		large_push_min_flag(env);
	}
	large_last_rotate(env);
	return ;
}
