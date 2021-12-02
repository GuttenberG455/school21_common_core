/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:55:13 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/02 14:23:48 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{	
	t_env		*env;
	t_lstack	*stack_a;
	t_lstack	*stack_b;

	env = malloc(sizeof(t_env *));
	env->stack_a = &stack_a;
	env->stack_b = &stack_b;
	env->step_count = 0;
	env->max = 0;
	env->mid = 0;
	env->flag = 0;
	if (create_start_stack(env, argc, argv))
	{
		printf("ERROR\n");
		return (1);
	}
	ft_print_list(env->stack_a);
	printf("-------------------------\n");
	if (!is_sorted(env->stack_a))
		return (0);
	if (argc <= 7)
		tiny_sort(env);
	else
		large_sort(env);
	printf("-----Sorted Stack A------\n");
	ft_print_list(env->stack_a);
	printf("-----Steps %d------\n", env->step_count);
	// free(env);
	return (0);
}

/*
0. Понять что вообще нужно сделать
1. Убрать stdio.h
2. Сократить кол-во операций посредсвом записи все в одну строку, и заменой sa sb на ss
2. Сами вводим инструкции
3. Сообщение об ошибке
3. Проверка на ввод: неправильные инструкции, не интежер, 
3. Норма
4. ФЛАГИ
5. Мейкфайл
6. Тестеры
7. Хуестеры
8. Бонусы
9. Ебобонусы
21. ?????????
42. PROFIT!
*/
