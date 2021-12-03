/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:44:07 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/03 13:29:59 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 48 || str[i] > 57) && (str[i] != '-' && str[i] != '+'))
			return (0);
		i++;
	}
	return (1);
}

int	is_dublicate(t_lstack **stack)
{
	size_t		i;
	t_lstack	*iter;

	iter = *stack;
	i = 0;
	while (i < ft_lstack_len(stack) - 1)
	{
		if (get_value_by_order(stack, i) == get_value_by_order(stack, i + 1))
			return (1);
		i++;
		iter = *stack;
	}
	return (0);
}

int	get_value_by_order(t_lstack **stack, int ord)
{
	t_lstack	*iter;

	iter = *stack;
	while (iter)
	{
		if (iter->order == ord)
		{
			return (iter->value);
		}
		iter = iter->next;
	}
	return (0);
}
