/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:24:51 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/03 13:37:19 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	large_first_push(t_env *env)
{
	int			i;
	t_lstack	*iter;

	i = 0;
	env->looking = 0;
	env->flag = 1;
	env->max = (int) ft_lstack_len(env->stack_a) - 1;
	env->mid = env->max / 2 + env->looking;
	while (i <= env->max)
	{
		iter = *env->stack_a;
		if (iter->order <= env->mid)
			oper_pa(env);
		else
			oper_ra(env);
		i++;
	}
}

void	large_no_flag_push(t_env *env)
{
	t_lstack	*iter;
	int			i;

	i = 0;
	iter = *env->stack_a;
	if (large_fast_sort_two(env, 0))
		return ;
	env->max = (int) ft_lstack_len(env->stack_a) - 1;
	env->mid = env->max / 2 + env->looking;
	while (i <= env->max)
	{
		iter = *env->stack_a;
		if (iter->order <= env->mid && iter->flag == 0)
			oper_pa(env);
		else
			oper_ra(env);
		i++;
	}
}

void	large_flag_push(t_env *env)
{
	t_lstack	*iter;
	int			upper_flag;

	iter = *env->stack_a;
	upper_flag = iter->flag;
	if (large_fast_sort_two(env, upper_flag))
		return ;
	iter = *env->stack_a;
	while (iter->flag == upper_flag)
	{
		oper_pa(env);
		iter = *env->stack_a;
	}
}

void	large_b_sort(t_env *env)
{
	t_lstack	*iter;

	if (ft_lstack_len(env->stack_b) == 0)
		return ;
	env->max = env->mid;
	env->mid = (env->max - env->looking) / 2 + env->looking;
	env->flag++;
	if (large_fast_b_two_three(env))
		return ;
	while (ft_lstack_len(env->stack_b))
	{
		iter = *env->stack_b;
		if (iter->order == env->looking)
		{
			oper_pb(env);
			oper_ra(env);
			env->looking++;
		}
		else if (iter->order > env->mid)
			oper_pb(env);
		else
			oper_rb(env);
	}
}

void	large_sort(t_env *env)
{
	t_lstack	*iter;
	int			list_count;

	list_count = ft_lstack_len(env->stack_a) - 1;
	large_first_push(env);
	while (is_sorted(env->stack_a) && env->looking != list_count)
	{
		if (!ft_lstack_len(env->stack_b))
		{	
			if (!iter->flag)
				large_no_flag_push(env);
			else
				large_flag_push(env);
		}
		large_b_sort(env);
		iter = *env->stack_a;
	}
	return ;
}
