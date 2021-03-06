/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:37:17 by majacqua          #+#    #+#             */
/*   Updated: 2022/07/25 14:39:21 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_env	env;

	validate_input(argc, argv);	// валидация аргументов
	env.map = get_map(argv[1]);	// создание карты
	env.size = (float)RES_X / (float)env.map->width;	// шаг, между разрешением окна и шириной карты
	env.player = create_player(env.map, &env);	// создание игрока
	env.mlx = mlx_init();	// инициализация mlx
	env.map->no_img = new_img_xpm(env.mlx, env.map->no_path);	// наши картинки 
	env.map->so_img = new_img_xpm(env.mlx, env.map->so_path);
	env.map->ea_img = new_img_xpm(env.mlx, env.map->ea_path);
	env.map->we_img = new_img_xpm(env.mlx, env.map->we_path);
	env.win = mlx_new_window(env.mlx, RES_X, RES_Y, "Game");	// создание окна
	render(&env);	// рендер
	set_hooks(&env);	// нажатие клавиш
	mlx_loop(env.mlx);	// залупливание
	return (0);
}
