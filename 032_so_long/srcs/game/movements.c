/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:29:32 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/15 17:23:21 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void	player_move_up(t_program *program)
{	
	t_vector	next_pos;
	
	next_pos = program->player.cur_pos;
	next_pos.y--;
	if (map_check_exit(program, next_pos))
		ft_close();
	if (program->map.grid[next_pos.y][next_pos.x] != '1' &&
		program->map.grid[next_pos.y][next_pos.x] != 'E')
	{
		if (program->map.grid[next_pos.y][next_pos.x] == 'C')
			program->map.coins_count--;
		program->map.grid[next_pos.y][next_pos.x] = 'P';
		program->map.grid[next_pos.y + 1][next_pos.x] = '0';
		program->player.step_count++;
		program->player.cur_pos = next_pos;
		printf("Steps -> %d\n", program->player.step_count);
	}
}

void	player_move_down(t_program *program)
{	
	t_vector	next_pos;
	
	next_pos = program->player.cur_pos;
	next_pos.y++;
	if (map_check_exit(program, next_pos))
		ft_close();
	if (program->map.grid[next_pos.y][next_pos.x] != '1' &&
		program->map.grid[next_pos.y][next_pos.x] != 'E')
	{
		if (program->map.grid[next_pos.y][next_pos.x] == 'C')
			program->map.coins_count--;
		program->map.grid[next_pos.y][next_pos.x] = 'P';
		program->map.grid[next_pos.y - 1][next_pos.x] = '0';
		program->player.step_count++;
		program->player.cur_pos = next_pos;
		printf("Steps -> %d\n", program->player.step_count);
	}
}

void	player_move_left(t_program *program)
{	
	t_vector	next_pos;
	
	next_pos = program->player.cur_pos;
	next_pos.x--;
	if (map_check_exit(program, next_pos))
		ft_close();
	if (program->map.grid[next_pos.y][next_pos.x] != '1' &&
		program->map.grid[next_pos.y][next_pos.x] != 'E')
	{
		if (program->map.grid[next_pos.y][next_pos.x] == 'C')
			program->map.coins_count--;
		program->map.grid[next_pos.y][next_pos.x] = 'P';
		program->map.grid[next_pos.y][next_pos.x + 1] = '0';
		program->player.step_count++;
		program->player.cur_pos = next_pos;
		printf("Steps -> %d\n", program->player.step_count);
	}
}

void	player_move_right(t_program *program)
{	
	t_vector	next_pos;
	
	next_pos = program->player.cur_pos;
	next_pos.x++;
	if (map_check_exit(program, next_pos))
		ft_close();
	if (program->map.grid[next_pos.y][next_pos.x] != '1' &&
		program->map.grid[next_pos.y][next_pos.x] != 'E')
	{
		if (program->map.grid[next_pos.y][next_pos.x] == 'C')
			program->map.coins_count--;
		program->map.grid[next_pos.y][next_pos.x] = 'P';
		program->map.grid[next_pos.y][next_pos.x - 1] = '0';
		program->player.step_count++;
		program->player.cur_pos = next_pos;
		printf("Steps -> %d\n", program->player.step_count);
	}
}