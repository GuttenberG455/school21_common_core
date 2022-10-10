/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:29:32 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/23 19:55:08 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	player_move_up(t_prog *prog)
{	
	t_vector	next_pos;

	next_pos = prog->player.cur_pos;
	next_pos.y--;
	if (map_check_gameover(prog, next_pos))
		ft_close("Well Done\nYou have been escaped from Dankest Dungeon"); // наверное тоже надо очистить
	if (prog->map.grid[next_pos.y][next_pos.x] != '1' &&
		prog->map.grid[next_pos.y][next_pos.x] != 'E')
	{
		if (prog->map.grid[next_pos.y][next_pos.x] == 'C')
		{
			draw_sprite_ground(*prog, next_pos.x * 32, next_pos.y * 32);
			prog->map.coins_count--;
		}
		make_player_move(prog, prog->player.cur_pos, next_pos);
	}
}

void	player_move_down(t_prog *prog)
{	
	t_vector	next_pos;

	next_pos = prog->player.cur_pos;
	next_pos.y++;
	if (map_check_gameover(prog, next_pos))
		ft_close("Well Done\nYou have been escaped from Dankest Dungeon");
	if (prog->map.grid[next_pos.y][next_pos.x] != '1' &&
		prog->map.grid[next_pos.y][next_pos.x] != 'E')
	{
		if (prog->map.grid[next_pos.y][next_pos.x] == 'C')
		{
			draw_sprite_ground(*prog, next_pos.x * 32, next_pos.y * 32);
			prog->map.coins_count--;
		}
		make_player_move(prog, prog->player.cur_pos, next_pos);
	}
}

void	player_move_left(t_prog *prog)
{	
	t_vector	next_pos;

	next_pos = prog->player.cur_pos;
	next_pos.x--;
	if (map_check_gameover(prog, next_pos))
		ft_close("Well Done\nYou have been escaped from Dankest Dungeon");
	if (prog->map.grid[next_pos.y][next_pos.x] != '1' &&
		prog->map.grid[next_pos.y][next_pos.x] != 'E')
	{
		if (prog->map.grid[next_pos.y][next_pos.x] == 'C')
		{
			draw_sprite_ground(*prog, next_pos.x * 32, next_pos.y * 32);
			prog->map.coins_count--;
		}
		make_player_move(prog, prog->player.cur_pos, next_pos);
	}
}

void	player_move_right(t_prog *prog)
{	
	t_vector	next_pos;

	next_pos = prog->player.cur_pos;
	next_pos.x++;
	if (map_check_gameover(prog, next_pos))
		ft_close("Well Done\nYou have been escaped from Dankest Dungeon");
	if (prog->map.grid[next_pos.y][next_pos.x] != '1' &&
		prog->map.grid[next_pos.y][next_pos.x] != 'E')
	{
		if (prog->map.grid[next_pos.y][next_pos.x] == 'C')
		{
			draw_sprite_ground(*prog, next_pos.x * 32, next_pos.y * 32);
			prog->map.coins_count--;
		}
		make_player_move(prog, prog->player.cur_pos, next_pos);
	}
}
