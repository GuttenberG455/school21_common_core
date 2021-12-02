/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:08:55 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/02 15:42:55 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	large_fast_sort_two(t_env *env, int flag)
{
	t_lstack	*iter;
	int			count;

	count = 0;
	iter = *env->stack_a;
	while (iter->flag == flag)
	{
		count++;
		iter = iter->next;
	}
	if (count == 2)
	{
		sort_two(env, 0);
		oper_ra(env);
		oper_ra(env);
		return (1);
	}
	return (0);
}

int	large_fast_b_two_three(t_env *env)
{
	if (ft_lstack_len(env->stack_b) == 2)
	{
		sort_two(env, 1);
		oper_pb(env);
		oper_ra(env);
		oper_pb(env);
		oper_ra(env);
		env->looking += 2;
		return (1);
	}
	if (ft_lstack_len(env->stack_b) == 3)
	{
		sort_three_stack_b(env);
		oper_pb(env);
		oper_ra(env);
		oper_pb(env);
		oper_ra(env);
		oper_pb(env);
		oper_ra(env);
		env->looking += 3;
		return (1);
	}
	return (0);
}
