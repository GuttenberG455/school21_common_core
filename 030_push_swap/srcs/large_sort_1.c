/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:04:03 by majacqua          #+#    #+#             */
/*   Updated: 2021/11/27 17:12:04 by majacqua         ###   ########.fr       */
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
	printf("next:%d\tmax:%d\tmid:%d\n", env->looking, env->max, env->mid);
	while (i <= env->max)
	{
		iter = *env->stack_a;
		if (iter->order <= env->mid)
			op_push(env->stack_a, env->stack_b);
		else
			op_rotate_one(env->stack_a);
		i++;
	}
}

void	large_no_flag_push(t_env *env)
{
	int			i;
	t_lstack	*iter;

	i = 0;
	env->max = (int) ft_lstack_len(env->stack_a) - 1;
	env->mid = env->max / 2 + env->looking;
	printf("next:%d\tmax:%d\tmid:%d\n", env->looking, env->max, env->mid);
	while (i <= env->max)
	{
		iter = *env->stack_a;
		if (iter->order <= env->mid && iter->flag == 0)
			op_push(env->stack_a, env->stack_b);
		else
			op_rotate_one(env->stack_a);
		i++;
	}
}

void	large_b_first_sort(t_env *env)
{
	int			i;
	t_lstack	*iter;

	i = 0;
	env->max = env->mid;
	env->mid = (env->max - env->looking) / 2 + env->looking;
	env->flag++;
	if (ft_lstack_len(env->stack_b) == 2)
	{
		sort_two(env->stack_b);
		op_push(env->stack_b, env->stack_a);
		op_rotate_one(env->stack_a);
		env->looking++;
		op_push(env->stack_b, env->stack_a);
		op_rotate_one(env->stack_a);
		env->looking++;
		return ;
	}
	printf("next:%d\tmax:%d\tmid:%d\n", env->looking, env->max, env->mid);
	while (ft_lstack_len(env->stack_b))
	{
		iter = *env->stack_b;
		if (iter->order == env->looking)
		{
			op_push(env->stack_b, env->stack_a);
			op_rotate_one(env->stack_a);
			env->looking++;
		}
		else if (iter->order > env->mid)
			op_push(env->stack_b, env->stack_a);
		else
			op_rotate_one(env->stack_b);
		i++;
	}
}

void	large_flag_push(t_env *env)
{
	t_lstack	*iter;

	iter = *env->stack_a;
	printf("next:%d\tmax:%d\tmid:%d\n", env->looking, env->max, env->mid);
	while (iter->flag != 0)
	{
		op_push(env->stack_a, env->stack_b);
		iter = *env->stack_a;
	}
}
