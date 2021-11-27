/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:24:51 by majacqua          #+#    #+#             */
/*   Updated: 2021/11/27 17:15:35 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	large_sort(t_env *env)
{
	t_lstack	*iter;
	int 		list_count;
	int 		c = 0;
	
	list_count = ft_lstack_len(env->stack_a) - 1;
	large_first_push(env);
	while (is_sorted(env->stack_a) && env->looking != list_count)
	{
		large_b_first_sort(env);
		large_flag_push(env);
		printf("-----Try %d------\n", c);
		ft_print_list(env->stack_a);
		printf("-----\n");
		ft_print_list(env->stack_b);
		c++;
		iter = *env->stack_a;
		if (!iter->flag)
			large_no_flag_push(env);
	}
	return ;
}
