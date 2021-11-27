/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:02:58 by majacqua          #+#    #+#             */
/*   Updated: 2021/11/27 14:37:13 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	get_order_list(t_lstack **stack)
{
	size_t		size;
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
}

int	is_sorted(t_lstack **stack)
{
	t_lstack	*iter;
	int			order;

	order = 0;
	iter = *stack;
	while (iter)
	{
		if (iter->order != order)
			return (1);
		if (iter->next == 0)
			return (0);
		iter = iter->next;
		order++;
	}
	return (0);
}

int	create_start_stack(t_env *env, int argc, char **argv)
{
	int			i;
	t_lstack	*new;

	if (argc < 2)
		return (1);
	else
	{	
		i = 1;
		while (i < argc)
		{
			new = ft_create_list(ft_atoi(argv[i]));
			ft_push_list(env->stack_a, new);
			i++;
		}
		get_order_list(env->stack_a);
		return (0);
	}
}
