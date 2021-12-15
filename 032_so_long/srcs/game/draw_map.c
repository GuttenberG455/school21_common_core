/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:27:38 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/15 19:34:41 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"


void	draw_sprite_on_map(t_program program)
{
	int		i;
	int		j;
	char	ch;

	j = 0;
	while (j * 32 < program.window.size.y)
	{
		i = 0;
		while (i * 32 < program.window.size.x)
		{
			ch = program.map.grid[j][i];
			if (ch == '1')
				draw_sprite_wall(program, i * 32, j * 32);
			else if (ch == 'C')
				draw_sprite_coins(program, i * 32, j * 32);
			else if (ch == 'E')
				draw_sprite_exit(program, i * 32, j * 32);
			else if (ch == 'P')
				draw_sprite_player(program, i * 32, j * 32);
			i++;
		}
		j++;
	}
}

void	draw_empty_map(t_program program)
{
	int	i;
	int	j;


	j = 0;
	while (j < program.window.size.y)
	{
		i = 0;
		while (i < program.window.size.x)
		{
			program.sprite = ft_new_sprite(program.mlx, "../../images/ground.xpm");
			program.sprite_pos.x = i;
			program.sprite_pos.y = j;
			mlx_put_image_to_window(program.mlx, program.window.reference,
			program.sprite.reference, program.sprite_pos.x, program.sprite_pos.y);
			i += 32;
		}
		j += 32;
	}
}

void	draw_player(t_program program)
{
	program.sprite = ft_new_sprite(program.mlx, "../../images/player.xpm");
	program.sprite_pos.x = program.player.cur_pos.x * 32;
	program.sprite_pos.y = program.player.cur_pos.y * 32;
	mlx_put_image_to_window(program.mlx, program.window.reference,
		program.sprite.reference, program.sprite_pos.x, program.sprite_pos.y);
}

void	draw_map(t_program program)
{
	draw_empty_map(program);
	draw_sprite_on_map(program);
}