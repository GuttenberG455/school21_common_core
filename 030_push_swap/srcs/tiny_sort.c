/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:20:26 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/03 13:31:05 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	tiny_sort(t_env *env)
{	
	if (ft_lstack_len(env->stack_a) <= 2)
		sort_two(env, 0);
	else if (ft_lstack_len(env->stack_a) == 3)
		sort_three_stack_a(env);
	else if (ft_lstack_len(env->stack_a) >= 4)
		sort_four_to_six(env);
}
