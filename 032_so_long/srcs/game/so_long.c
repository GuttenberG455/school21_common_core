/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:51:37 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/15 20:06:53 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

int	main(int argc, char **argv)
{
	t_program	program;
	t_map		*map_ptr;

	map_ptr = create_map(argv[1]);
	if (!map_ptr)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	print_map(map_ptr->grid);
	// program.mlx = mlx_init();
	// program.map = *map_ptr;
	// print_map(program.map.grid);
	// program.window = ft_new_window(program.mlx, program.map);
	// draw_map(program);

	// mlx_key_hook(program.window.reference, *ft_input, &program);

	// mlx_loop(program.mlx);
}
/*
ПЕРЕСТАЛО ВООЬЩЕ ВСЕ РАБОТАТЬ
ПЗДЕК 

Скачать готовый вариант, проверить там скорость  и утечки со своими картами

РАЗОБРАТЬСЯ С ЕБАННОЙ ПАМЯТЬЮ
1. Сеги
2. Утечки
3. БАсы
4. Флаги
5. Хуяги
6. Хуейкфайл (про бонусы не забыть)
7. ХУЛИ так медленно ходит
8. Все что не влезает на маковский экран, не даем создать

БОНУСЫ-ХУЕНОСЫ
1. Враги, шо б с локтя пизды давали и чел отлетал в таверну и ггвп
*/
