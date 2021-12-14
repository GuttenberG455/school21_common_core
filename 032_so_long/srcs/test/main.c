/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:13:31 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/14 14:20:12 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

int	main(void)
{
	t_program	program;
	program.mlx = mlx_init();
	program.window = ft_new_window(program.mlx, 800, 600, "Dankest Dungeon");

	// program.sprite = ft_new_sprite(program.mlx, "../../images/wall2.xpm");
	// program.sprite_pos.x = 0;
	// program.sprite_pos.y = 0;
	// mlx_put_image_to_window(program.mlx, program.window.reference,
	// program.sprite.reference, program.sprite_pos.x, program.sprite_pos.y);

	// program.sprite = ft_new_sprite(program.mlx, "../../images/wall2.xpm");
	// program.sprite_pos.x = 32;
	// program.sprite_pos.y = 0;
	// mlx_put_image_to_window(program.mlx, program.window.reference,
	// program.sprite.reference, program.sprite_pos.x, program.sprite_pos.y);

	// program.sprite = ft_new_sprite(program.mlx, "../../images/wall2.xpm");
	// program.sprite_pos.x = 0;
	// program.sprite_pos.y = 32;
	// mlx_put_image_to_window(program.mlx, program.window.reference,
	// program.sprite.reference, program.sprite_pos.x, program.sprite_pos.y);
	
	// program.sprite = ft_new_sprite(program.mlx, "../../images/ground2.xpm");
	// program.sprite_pos.x = 32;
	// program.sprite_pos.y = 32;
	// mlx_put_image_to_window(program.mlx, program.window.reference,
	// program.sprite.reference, program.sprite_pos.x, program.sprite_pos.y);

	// program.sprite = ft_new_sprite(program.mlx, "../../images/ground2.xpm");
	// program.sprite_pos.x = 64;
	// program.sprite_pos.y = 32;
	// mlx_put_image_to_window(program.mlx, program.window.reference,
	// program.sprite.reference, program.sprite_pos.x, program.sprite_pos.y);

	// program.sprite = ft_new_sprite(program.mlx, "../../images/ground2.xpm");
	// program.sprite_pos.x = 32;
	// program.sprite_pos.y = 64;
	// mlx_put_image_to_window(program.mlx, program.window.reference,
	// program.sprite.reference, program.sprite_pos.x, program.sprite_pos.y);

	// program.sprite = ft_new_sprite(program.mlx, "../../images/coins.xpm");
	// program.sprite_pos.x = 64;
	// program.sprite_pos.y = 32;
	// mlx_put_image_to_window(program.mlx, program.window.reference,
	// program.sprite.reference, program.sprite_pos.x, program.sprite_pos.y);

	// program.sprite = ft_new_sprite(program.mlx, "../../images/exit_2.xpm");
	// program.sprite_pos.x = 32;
	// program.sprite_pos.y = 64;
	// mlx_put_image_to_window(program.mlx, program.window.reference,
	// program.sprite.reference, program.sprite_pos.x, program.sprite_pos.y);
	
	program.sprite = ft_new_sprite(program.mlx, "../../images/player.xpm");
	program.sprite_pos.x = 32;
	program.sprite_pos.y = 32;
	mlx_put_image_to_window(program.mlx, program.window.reference,
	program.sprite.reference, program.sprite_pos.x, program.sprite_pos.y);

	mlx_key_hook(program.window.reference, *ft_input, &program);
	mlx_loop_hook(program.mlx, *ft_update, &program);
	
	mlx_loop(program.mlx);
}