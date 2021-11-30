/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:24:51 by majacqua          #+#    #+#             */
/*   Updated: 2021/11/30 17:44:26 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	large_sort(t_env *env)
{
	t_lstack	*iter;
	int			list_count;
	int 		c = 0;

	list_count = ft_lstack_len(env->stack_a) - 1;
	large_first_push(env);
	while (is_sorted(env->stack_a) && env->looking != list_count)
	{
		printf("-----Try %d- START-----\n", c);
		ft_print_env(env);
		if (!ft_lstack_len(env->stack_b))
		{	
			if (!iter->flag)
				large_no_flag_push(env);
			else
				large_flag_push(env);
		}
		ft_print_env(env);
		large_b_first_sort(env);
		ft_print_env(env);
		c++;
		iter = *env->stack_a;
	}
	return ;
}
