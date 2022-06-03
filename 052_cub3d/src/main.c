/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:37:17 by majacqua          #+#    #+#             */
/*   Updated: 2022/06/03 17:03:29 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_env env;
	
	validate_input(argc, argv);
	env.map = get_map(argv[1]);
	env.size = (float)RES_X / (float)env.map->width;
	env.player = create_player(env.map, &env);
	print_map(env.map);
	print_player(env.player);
	printf("Size = %f\n", env.size);
	env.mlx = mlx_init();
	env.map->no_img = new_img_xpm(env.mlx, env.map->no_path);
	env.map->so_img = new_img_xpm(env.mlx, env.map->so_path);
	env.map->ea_img = new_img_xpm(env.mlx, env.map->ea_path);
	env.map->we_img = new_img_xpm(env.mlx, env.map->we_path);
	env.win = mlx_new_window(env.mlx, RES_X, RES_Y, "Game");
	render(&env);
	set_hooks(&env);
	mlx_loop(env.mlx);
	return (0);	
}
