/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:13:03 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/15 13:03:17 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void map_get_player_pos(t_program *program)
{
	int		i;
	int		j;

	j = 0;
	while (program->map.grid[j])
	{
		i = 0;
		while (program->map.grid[j][i])
		{
			if (program->map.grid[j][i] == 'P')
			{
				program->player.cur_pos.x = i;
				program->player.cur_pos.y = j;
				return ;
			}
			i++;
		}
		j++;
	}
}

int	map_check_exit(t_program *program, t_vector next_pos)
{
	if (program->map.grid[next_pos.y][next_pos.x] == 'E')
	{
		if (program->map.coins_count == 0)
			return (1);
	}
	return (0);
}