/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:55:13 by majacqua          #+#    #+#             */
/*   Updated: 2021/11/24 15:22:35 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{	
	t_lstack	*stack_a;
	t_lstack	*stack_b;
	t_lstack	*iter;

	create_start_stack(&stack_a, argc, argv);
	ft_print_list(&stack_a);
	printf("-----\n");
	ft_print_list(&stack_b);
	printf("-------------------------\n");
	if (argc < 6)
		tiny_sort(&stack_a, &stack_b);
	else
		large_sort(&stack_a, &stack_b);
	ft_print_list(&stack_a);
	return (0);
}

//не работает сортировка