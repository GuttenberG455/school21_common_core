/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:51:37 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/14 19:00:01 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

int	main(void)
{
	t_program	program;
	program.mlx = mlx_init();
	program.map = create_map("../../maps/subj.ber");
	print_map(program.map->grid);
	program.window = ft_new_window(program.mlx, program.map);
	draw_map(program);
	
	program.sprite = ft_new_sprite(program.mlx, "../../images/player.xpm");
	program.sprite_pos.x = 32;
	program.sprite_pos.y = 32;
	mlx_put_image_to_window(program.mlx, program.window.reference,
	program.sprite.reference, program.sprite_pos.x, program.sprite_pos.y);
	
	mlx_key_hook(program.window.reference, *ft_input, &program);
	mlx_loop_hook(program.mlx, *ft_update, &program);
	
	mlx_loop(program.mlx);
}

/* TODO
Структуры
1. Карта в реальном времени, по которой ходит P. Через 1 ходить нельзя, C собирается, через Е выходим
2. Подсчет действий, оставшееся количество монет в структуре игры

Функция
1. Отрисовка текущей карты
2. Перемещение игрока

*/