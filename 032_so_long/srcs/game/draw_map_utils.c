/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:22:51 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/14 18:43:29 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void draw_sprite_wall(t_program program, int i, int j)
{
	program.sprite = ft_new_sprite(program.mlx, "../../images/wall.xpm");
	program.sprite_pos.x = i;
	program.sprite_pos.y = j;
	mlx_put_image_to_window(program.mlx, program.window.reference,
	program.sprite.reference, program.sprite_pos.x, program.sprite_pos.y);
}

void draw_sprite_coins(t_program program, int i, int j)
{
	program.sprite = ft_new_sprite(program.mlx, "../../images/coins.xpm");
	program.sprite_pos.x = i;
	program.sprite_pos.y = j;
	mlx_put_image_to_window(program.mlx, program.window.reference,
	program.sprite.reference, program.sprite_pos.x, program.sprite_pos.y);
}

void draw_sprite_exit(t_program program, int i, int j)
{
	program.sprite = ft_new_sprite(program.mlx, "../../images/exit_2.xpm");
	program.sprite_pos.x = i;
	program.sprite_pos.y = j;
	mlx_put_image_to_window(program.mlx, program.window.reference,
	program.sprite.reference, program.sprite_pos.x, program.sprite_pos.y);
}