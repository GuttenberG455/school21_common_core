/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:55:13 by majacqua          #+#    #+#             */
/*   Updated: 2021/11/23 19:59:43 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{	
	t_lstack	*stack_a;
	t_lstack	*stack_b;

	create_start_stack(&stack_a, argc, argv);
	printf("Swap A\n");
	op_swap_one(&stack_a);
	ft_print_list(&stack_a);
	printf("Push three from A to B\n");
	op_push(&stack_a, &stack_b);
	op_push(&stack_a, &stack_b);
	op_push(&stack_a, &stack_b);
	ft_print_list(&stack_b);
	printf("------------\n");
	ft_print_list(&stack_a);
	return (0);
}
