/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:27:38 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/23 18:44:46 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/ft_printf.h"


void	draw_sprite_ground(t_prog prog, int i, int j)
{
	prog.sprite = ft_new_sprite(prog.mlx, "images/ground.xpm");
	prog.sprite.pos.x = i;
	prog.sprite.pos.y = j;
	mlx_put_image_to_window(prog.mlx, prog.window.ptr,
		prog.sprite.ptr, prog.sprite.pos.x, prog.sprite.pos.y);
	mlx_destroy_image(prog.mlx, prog.sprite.ptr);
}

void	draw_sprites_on_map(t_prog prog)
{
	int		i;
	int		j;
	char	ch;

	j = 0;
	while (j * 32 < prog.window.size.y)
	{
		i = 0;
		while (i * 32 < prog.window.size.x)
		{
			ch = prog.map.grid[j][i];
			if (ch == '1')
				draw_sprite_wall(prog, i * 32, j * 32);
			else if (ch == 'C')
				draw_sprite_coins(prog, i * 32, j * 32);
			else if (ch == 'E')
				draw_sprite_exit(prog, i * 32, j * 32);
			else if (ch == 'P')
				draw_sprite_player(prog, i * 32, j * 32);
			else if (ch == 'Q')
				draw_sprite_enemy(prog, i * 32, j * 32);
			i++;
		}
		j++;
	}
}

void	make_player_move(t_prog *prog, t_vector old_pos, t_vector next_pos)
{
	(*prog).map.grid[next_pos.y][next_pos.x] = 'P';
	(*prog).map.grid[old_pos.y][old_pos.x] = '0';
	(*prog).player.step_count++;
	(*prog).player.cur_pos = next_pos;
	draw_sprite_player(*prog, next_pos.x * 32, next_pos.y * 32);
	draw_sprite_ground(*prog, old_pos.x * 32, old_pos.y * 32);
	ft_printf("Steps -> %d\n", prog->player.step_count);
}

void	draw_empty_map(t_prog prog)
{
	int	i;
	int	j;

	j = 0;
	while (j < prog.window.size.y)
	{
		i = 0;
		while (i < prog.window.size.x)
		{
			draw_sprite_ground(prog, i, j);
			i += 32;
		}
		j += 32;
	}
}

void	draw_map(t_prog prog)
{
	draw_empty_map(prog);
	draw_sprites_on_map(prog);
}
