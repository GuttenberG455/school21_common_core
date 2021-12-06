/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:08:55 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/06 14:55:47 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_current_pos(t_lstack **stack, int num)
{
	t_lstack	*iter;
	size_t		pos;

	if (!stack || !*stack)
		return (0);
	pos = 0;
	iter = *stack;
	while (iter)
	{
		if (iter->value == num)
			return (pos);
		if (iter->next == 0)
			return (pos);
		iter = iter->next;
		pos++;
	}
	return (pos);
}

int	count_steps_to_top(t_lstack **stack, int num)
{
	int	pos;
	int	rpos;

	pos = get_current_pos(stack, num);
	rpos = pos - ft_lstack_len(stack);
	if (ft_abs(pos) <= ft_abs(rpos))
		return (pos);
	else
		return (rpos);
}

int	find_closest_big(t_lstack **stack, int num)
{
	t_lstack	*iter;
	int			max;

	max = INT_MAX;
	iter = *stack;
	while (iter)
	{
		if (iter->value < max && iter->value > num)
			max = iter->value;
		iter = iter->next;
	}
	return (max);
}

int	count_correct_position(t_env *env, t_lstack	*node)
{
	int			closest;
	int			count;
	t_lstack	*iter;

	count = ft_abs(count_steps_to_top(env->stack_b, node->value));
	closest = find_closest_big(env->stack_a, node->value);
	count += ft_abs(count_steps_to_top(env->stack_a, closest));
	return (count);
}

void	large_count_flags(t_env *env)
{
	t_lstack	*iter;
	int			i;

	i = 0;
	iter = *env->stack_b;
	while (i < ft_lstack_len(env->stack_b))
	{
		iter->flag = count_correct_position(env, iter);
		iter = iter->next;
		i++;
	}
}
