/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:55:13 by majacqua          #+#    #+#             */
/*   Updated: 2021/11/30 18:47:20 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{	
	t_env		*env;
	t_lstack	*stack_a;
	t_lstack	*stack_b;
	t_lstack	*iter;

	env = malloc(sizeof(t_env *));
	env->stack_a = &stack_a;
	env->stack_b = &stack_b;
	if (create_start_stack(env, argc, argv))
		return (1);
	ft_print_list(env->stack_a);
	printf("-------------------------\n");
	if (!is_sorted(env->stack_a))
		return (0);
	if (argc <= 7)
		tiny_sort(env);
	else
		large_sort(env);
	printf("-----Sorted Stack A------\n");
	ft_print_env(env);
	printf("-----Steps %d------\n", env->step_count);
	return (0);
}

/*
1. Неправильный подсчет MID
2. Разобраться с флагами
3. Понять что вообще нужно сделать
4. ?????????
5. PROFIT!
NEXT HUYNA
TODO
1. Переделать тайни сорт, переписать все под новый env
2. Сократить кол-во операций для ларджа (сортировку 2-3)
3. Сделать счетчик операций?????
4. 
*/
