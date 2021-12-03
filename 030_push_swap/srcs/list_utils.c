/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:24:07 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/03 16:46:16 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_lstack	*ft_create_list(int value)
{
	t_lstack	*ptr;

	ptr = (t_lstack *)malloc(sizeof(t_lstack));
	if (!(ptr))
		return (0);
	ptr->value = value;
	ptr->order = 0;
	ptr->flag = 0;
	ptr->prev = 0;
	ptr->next = 0;
	return (ptr);
}

void	ft_print_list(t_lstack **stack)
{
	t_lstack	*iter;

	if (!stack)
		return ;
	iter = *stack;
	while (iter)
	{
		printf("%p _%d_ -value |%d|%d| next-%p prev-%p\n", iter, iter->value, iter->order, iter->flag, iter->next, iter->prev);
		iter = iter->next;
	}
}

void	ft_push_list(t_lstack **stack, t_lstack *new)
{
	t_lstack	*iter;

	if (*stack == 0)
	{
		iter = new;
		*stack = new;
		new->order = -1;
		return ;
	}
	iter = *stack;
	while (iter)
	{
		if (iter->next == 0)
		{
			iter->next = new;
			new->order = -1;
			new->prev = iter;
			return ;
		}
		iter = iter->next;
	}
}

t_lstack	*ft_last_lstack(t_lstack **stack)
{
	t_lstack	*iter;

	if (!stack || !*stack)
		return (0);
	iter = *stack;
	while (iter)
	{
		if (iter->next == 0)
			return (iter);
		iter = iter->next;
	}
	return (iter);
}

size_t	ft_lstack_len(t_lstack **stack)
{
	t_lstack	*iter;
	size_t		len;

	if (!stack || !*stack)
		return (0);
	len = 0;
	iter = *stack;
	while (iter)
	{
		if (iter->next == 0)
			return (++len);
		iter = iter->next;
		len++;
	}
	return (len);
}

void	ft_print_env(t_env *env)
{
	ft_print_list(env->stack_a);
	printf("-- %d ENV_FLAG -\n", env->flag);
	ft_print_list(env->stack_b);
	printf("----------------------------\n");
}
