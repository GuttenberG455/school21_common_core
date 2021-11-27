/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:04:03 by majacqua          #+#    #+#             */
/*   Updated: 2021/11/27 13:55:24 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	large_first_push(t_lstack **stack1, t_lstack **stack2)
{
	int			mid_value;
	int			i;
	int			len_1;
	t_lstack	*iter;

	i = 0;
	len_1 = (int) ft_lstack_len(stack1) - 1;
	mid_value = len_1 / 2 + 1; // + NEXT
	while (i <= len_1)
	{
		iter = *stack1;
		if (iter->order < mid_value)
			op_push(stack1, stack2);
		else
			op_rotate_one(stack1);
		i++;
	}
}
