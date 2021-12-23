/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:13:03 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/23 19:54:47 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void	map_get_player_pos(t_prog *prog)
{
	int		i;
	int		j;

	j = 0;
	while (prog->map.grid[j])
	{
		i = 0;
		while (prog->map.grid[j][i])
		{
			if (prog->map.grid[j][i] == 'P')
			{
				prog->player.cur_pos.x = i;
				prog->player.cur_pos.y = j;
				return ;
			}
			i++;
		}
		j++;
	}
}

int	map_check_gameover(t_prog *prog, t_vector next_pos)
{
	if (prog->map.grid[next_pos.y][next_pos.x] == 'Q')
	{
		ft_close("GAME OVER\nYou have been pwned by ogre\n"); //что-то да очистить
	}
	if (prog->map.grid[next_pos.y][next_pos.x] == 'E')
	{
		if (prog->map.coins_count == 0)
			return (1);
	}
	return (0);
}
