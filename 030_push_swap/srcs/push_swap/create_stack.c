/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:02:58 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/08 15:02:16 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_order_list(t_lstack **stack)
{
	size_t		position;
	t_lstack	*min_stack;
	t_lstack	*iter;
	int			min_value;

	position = 0;
	iter = *stack;
	while (position < ft_lstack_len(stack))
	{
		min_value = INT_MAX;
		while (iter)
		{
			if (iter->value < min_value && iter->order == -1)
			{
				min_stack = iter;
				min_value = iter->value;
			}	
			iter = iter->next;
		}
		min_stack->order = position;
		position++;
		iter = *stack;
	}
	return (0);
}

int	create_start_stack(t_env *env, int argc, char **argv)
{
	int			i;
	long long	input_num;
	t_lstack	*new;

	if (argc < 2)
		return (1);
	else
	{	
		i = 1;
		while (i < argc)
		{
			input_num = ft_atoi(argv[i]);
			if ((ft_atoi(argv[i]) == 0 && argv[i][0] != '0')
				|| (input_num > INT_MAX || input_num < INT_MIN
				|| !is_number(argv[i])))
				return (1);
			new = ft_create_list(input_num);
			ft_push_list(env->stack_a, new);
			i++;
		}
		if (get_order_list(env->stack_a) || is_dublicate(env->stack_a)
			|| get_properties(env))
			return (1);
		return (0);
	}
}
