/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:02:58 by majacqua          #+#    #+#             */
/*   Updated: 2021/11/26 16:23:48 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_order_list(t_lstack **stack)
{
	size_t		size;
	size_t		position;
	t_lstack	*min_value;
	t_lstack	*iter;

	position = 0;
	iter = *stack;
	min_value->value = INT_MAX;
	while (position < ft_lstack_len(stack))
	{
		while (iter)
		{
			printf("Compare: %d %d pos-%zu\n", iter->value, min_value->value, position);
			if (iter->value < min_value->value && iter->order == -1)
			{
				min_value = iter;
			}
			iter = iter->next;
		}
		min_value->order = position;
		position++;
		iter = *stack;
	}
}
// не работает заполнение порядка на финише
int	create_start_stack(t_lstack **stack, int argc, char **argv)
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
			ft_push_list(stack, new);
			i++;
		}
		return (0);
	}
}
