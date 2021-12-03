/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:55:13 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/03 16:45:16 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{	
	t_env		*env;
	t_lstack	*stack_a;
	t_lstack	*stack_b;

	env = malloc(sizeof(t_env *));
	if (!env)
		return (1);
	env->stack_a = &stack_a;
	env->stack_b = &stack_b;
	env->step_count = 0;
	env->max = 0;
	env->mid = 0;
	env->flag = 0;
	if (create_start_stack(env, argc, argv))
	{
		ft_putstr_fd("ERROR\n", 1);
		return (1);
	}
	ft_print_list(env->stack_a);
	printf("-------------------------\n");
	if (!is_sorted(env->stack_a))
		return (0);
	if (argc <= 7)
		tiny_sort(env);
	else
		large_sort(env);
	printf("-----Sorted Stack A------\n");
	ft_print_list(env->stack_a);
	printf("-----Steps %d------\n", env->step_count);
	return (0);
}
