/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:03:00 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/15 19:57:50 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"


int	ft_input(int key, void *param)
{
	t_program	*program = (t_program *) param;
	
	mlx_clear_window(program->mlx, program->window.reference);
	map_get_player_pos(program);
	
	if (key == 13)
		player_move_up(program);
	else if (key == 0)
		player_move_left(program);
	else if (key == 1)
		player_move_down(program);
	else if (key == 2)
		player_move_right(program);
	else if (key == 53)
		ft_close();
	
	draw_map(*program);
	return (0);
}