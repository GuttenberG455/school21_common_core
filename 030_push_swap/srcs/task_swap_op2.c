/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_swap_op2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:06:19 by majacqua          #+#    #+#             */
/*   Updated: 2021/11/30 17:48:38 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	oper_ra(t_env *env)
{
	op_rotate_one(env->stack_a);
	env->step_count++;
	printf("ra\n");
}

void	oper_rb(t_env *env)
{
	op_rotate_one(env->stack_b);
	env->step_count++;
	printf("rb\n");
}

void	oper_rr(t_env *env)
{
	op_rotate_one(env->stack_a);
	op_rotate_one(env->stack_b);
	env->step_count++;
	printf("rr\n");
}
