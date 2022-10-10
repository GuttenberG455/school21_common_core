/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:22:51 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/23 18:22:29 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	draw_sprite_wall(t_prog prog, int i, int j)
{
	prog.sprite = ft_new_sprite(prog.mlx, "images/wall.xpm");
	prog.sprite.pos.x = i;
	prog.sprite.pos.y = j;
	mlx_put_image_to_window(prog.mlx, prog.window.ptr,
		prog.sprite.ptr, prog.sprite.pos.x, prog.sprite.pos.y);
	mlx_destroy_image(prog.mlx, prog.sprite.ptr);
}

void	draw_sprite_coins(t_prog prog, int i, int j)
{
	prog.sprite = ft_new_sprite(prog.mlx, "images/coins.xpm");
	prog.sprite.pos.x = i;
	prog.sprite.pos.y = j;
	mlx_put_image_to_window(prog.mlx, prog.window.ptr,
		prog.sprite.ptr, prog.sprite.pos.x, prog.sprite.pos.y);
	mlx_destroy_image(prog.mlx, prog.sprite.ptr);
}

void	draw_sprite_exit(t_prog prog, int i, int j)
{
	prog.sprite = ft_new_sprite(prog.mlx, "images/exit.xpm");
	prog.sprite.pos.x = i;
	prog.sprite.pos.y = j;
	mlx_put_image_to_window(prog.mlx, prog.window.ptr,
		prog.sprite.ptr, prog.sprite.pos.x, prog.sprite.pos.y);
	mlx_destroy_image(prog.mlx, prog.sprite.ptr);
}

void	draw_sprite_player(t_prog prog, int i, int j)
{
	prog.sprite = ft_new_sprite(prog.mlx, "images/player.xpm");
	prog.sprite.pos.x = i;
	prog.sprite.pos.y = j;
	mlx_put_image_to_window(prog.mlx, prog.window.ptr,
		prog.sprite.ptr, prog.sprite.pos.x, prog.sprite.pos.y);
	mlx_destroy_image(prog.mlx, prog.sprite.ptr);
}

void	draw_sprite_enemy(t_prog prog, int i, int j)
{
	prog.sprite = ft_new_sprite(prog.mlx, "images/enemy.xpm");
	prog.sprite.pos.x = i;
	prog.sprite.pos.y = j;
	mlx_put_image_to_window(prog.mlx, prog.window.ptr,
		prog.sprite.ptr, prog.sprite.pos.x, prog.sprite.pos.y);
	mlx_destroy_image(prog.mlx, prog.sprite.ptr);
}
