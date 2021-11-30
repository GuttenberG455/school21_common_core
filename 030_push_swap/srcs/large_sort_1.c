/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:04:03 by majacqua          #+#    #+#             */
/*   Updated: 2021/11/30 17:44:41 by majacqua         ###   ########.fr       */
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
	printf("Fitst: next:%d\tmax:%d\tmid:%d\n", env->looking, env->max, env->mid);
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
	int			i;
	t_lstack	*iter;

	i = 0;
	env->max = (int) ft_lstack_len(env->stack_a) - 1;
	env->mid = env->max / 2 + env->looking;
	printf("No_Flag: next:%d\tmax:%d\tmid:%d\n", env->looking, env->max, env->mid);
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

void	large_b_first_sort(t_env *env)
{
	int			i;
	t_lstack	*iter;

	i = 0;
	env->max = env->mid;
	env->mid = (env->max - env->looking) / 2 + env->looking;
	env->flag++;
	printf("B Sort: next:%d\tmax:%d\tmid:%d\n", env->looking, env->max, env->mid);
	if (ft_lstack_len(env->stack_b) == 2)
	{
		sort_two(env->stack_b);
		oper_pb(env);
		oper_ra(env);
		oper_pb(env);
		oper_ra(env);
		env->looking += 2;
		return ;
	}
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
		i++;
	}
}

void	large_flag_push(t_env *env)
{
	t_lstack	*iter;
	int			upper_flag;

	iter = *env->stack_a;
	upper_flag = iter->flag;
	printf("Flag Push: next:%d\tmax:%d\tmid:%d\n", env->looking, env->max, env->mid);
	printf("[%d]-[%d]\n", iter->flag, upper_flag);
	while (iter->flag == upper_flag)
	{
		printf("[%d]-[%d]\n", iter->flag, upper_flag);
		oper_pa(env);
		iter = *env->stack_a;
	}
}

int	is_all_flags(t_lstack **stack)
{
	t_lstack	*iter;

	iter = *stack;
	while (iter)
	{
		if (iter->flag == 0)
			return (1);
		if (iter->next == 0)
			return (0);
		iter = iter->next;
	}
	return (0);
}
