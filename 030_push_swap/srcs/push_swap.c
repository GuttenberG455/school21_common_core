/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:55:13 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/05 15:47:52 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{	
	t_env		*env;
	t_lstack	*stack_a;
	t_lstack	*stack_b;

	env = malloc(sizeof(t_env *));
	if (!env)
		return (1);
	env->stack_a = &stack_a;
	env->stack_b = &stack_b;
	env->step_count = 0;
	env->max = 0;
	env->mid = 0;
	env->min = 0;
	if (create_start_stack(env, argc, argv))
	{
		ft_putstr_fd("ERROR\n", 1);
		return (1);
	}
	ft_print_list(env->stack_a);
	printf("-------------------------\n");
	printf("MIN-%d[%d] MAX-%d[%lu] MID- %d[%lu]", env->min, 0,
		env->max, ft_lstack_len(env->stack_a) - 1, env->mid,
		(ft_lstack_len(env->stack_a) - 1) / 2 + 1);
	if (!is_sorted(env->stack_a))
		return (0);
	if (argc <= 7)
		tiny_sort(env);
	else
		large_sort(env);
	// printf("-----Sorted Stack A------\n");
	// ft_print_list(env->stack_a);
	// printf("-----Steps %d------\n", env->step_count);
	return (0);
}

/*
1. Находим MID и пушим в В (pa)
2. Пушим все элементы A в В кроме MIN и MAX так что (<MID) MID (>MAX)
3. Считаем для каждого В сколько нужно шагов до позиции в А (<A[0]) rb rrb + ra rra
4. Находим минимальный флаг и выполняем
... перечитываем, пушим, крутим до тех пор пока не закончатся элементы в В
5. Докручиваем А до отсортированного.

Функции:
+ 1. Поиск MIN, MAX, MID
+ Подсчет шагов от позиции до верхнего места в стаке.
+ 2. ПУШ MID в В
+ 3. ПУШ всех элементов А в В
4. Подсчет шагов для В на позицию
5. Выполняем пуш из В в А на позицию
6. Ротейт до отсортированного
*/