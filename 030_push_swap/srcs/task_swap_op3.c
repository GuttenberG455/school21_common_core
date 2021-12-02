/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_swap_op3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:19:39 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/02 10:01:44 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	oper_rra(t_env *env)
{
	op_reverse_rotate_one(env->stack_a);
	env->step_count++;
	printf("rra\n");
}

void	oper_rrb(t_env *env)
{
	op_reverse_rotate_one(env->stack_b);
	env->step_count++;
	printf("rrb\n");
}

void	oper_rrr(t_env *env)
{
	op_reverse_rotate_one(env->stack_a);
	op_reverse_rotate_one(env->stack_b);
	env->step_count++;
	printf("rrr\n");
}
