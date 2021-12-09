/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_swap_op1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:14:41 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/08 13:41:01 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	oper_sa(t_env *env)
{
	op_swap_one(env->stack_a);
	env->step_count++;
}

void	oper_sb(t_env *env)
{
	op_swap_one(env->stack_b);
	env->step_count++;
}

void	oper_ss(t_env *env)
{
	op_swap_one(env->stack_a);
	op_swap_one(env->stack_b);
	env->step_count++;
}

void	oper_pa(t_env *env)
{
	op_push(env->stack_b, env->stack_a, 0);
	env->step_count++;
}

void	oper_pb(t_env *env)
{
	op_push(env->stack_a, env->stack_b, 1);
	env->step_count++;
}
