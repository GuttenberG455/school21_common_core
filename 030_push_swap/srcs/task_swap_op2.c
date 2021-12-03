/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_swap_op2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:06:19 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/03 13:36:47 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	oper_ra(t_env *env)
{
	op_rotate_one(env->stack_a);
	env->step_count++;
	ft_putstr_fd("ra\n", 1);
}

void	oper_rb(t_env *env)
{
	op_rotate_one(env->stack_b);
	env->step_count++;
	ft_putstr_fd("rb\n", 1);
}

void	oper_rr(t_env *env)
{
	op_rotate_one(env->stack_a);
	op_rotate_one(env->stack_b);
	env->step_count++;
	ft_putstr_fd("rr\n", 1);
}
