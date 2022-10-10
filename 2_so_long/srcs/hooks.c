/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 11:47:22 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/23 19:54:10 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	ft_input(int key, void *param)
{
	t_prog	*prog;

	prog = (t_prog *) param;
	map_get_player_pos(prog);
	if (key == 13)
		player_move_up(prog);
	else if (key == 0)
		player_move_left(prog);
	else if (key == 1)
		player_move_down(prog);
	else if (key == 2)
		player_move_right(prog);
	else if (key == 53)
		ft_close("You pressed ESC\n"); // надо что-то очистить
	return (0);
}
