/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_swap_op1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:14:41 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/02 10:01:30 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	oper_sa(t_env *env)
{
	op_swap_one(env->stack_a);
	env->step_count++;
	printf("sa\n");
}

void	oper_sb(t_env *env)
{
	op_swap_one(env->stack_b);
	env->step_count++;
	printf("sb\n");
}

void	oper_ss(t_env *env)
{
	op_swap_one(env->stack_a);
	op_swap_one(env->stack_b);
	env->step_count++;
	printf("ss\n");
}

void	oper_pa(t_env *env)
{
	op_push(env->stack_a, env->stack_b, 1, env);
	env->step_count++;
	printf("pa\n");
}

void	oper_pb(t_env *env)
{
	op_push(env->stack_b, env->stack_a, 0, env);
	env->step_count++;
	printf("pb\n");
}
