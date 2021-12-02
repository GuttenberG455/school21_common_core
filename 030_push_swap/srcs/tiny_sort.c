/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:20:26 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/02 09:15:12 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	tiny_two(t_env *env)
{
	sort_two(env, 0);
}

void	tiny_three(t_env *env)
{
	sort_three_stack_a(env);
}

void	tiny_sort(t_env *env)
{	
	if (ft_lstack_len(env->stack_a) <= 2)
		tiny_two(env);
	else if (ft_lstack_len(env->stack_a) == 3)
		tiny_three(env);
	else if (ft_lstack_len(env->stack_a) >= 4)
		sort_four_to_six(env);
}
