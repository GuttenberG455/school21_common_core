/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:03:00 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/14 18:50:17 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"


int	ft_input(int key, void *param)
{
	t_program	*program = (t_program *) param;
	
	// mlx_clear_window(program->mlx, program->window.reference);
	
	if (key == 13)
		program->sprite_pos.y -= program->sprite.size.y;
	else if (key == 0)
		program->sprite_pos.x -= program->sprite.size.x;
	else if (key == 1)
		program->sprite_pos.y += program->sprite.size.y;
	else if (key == 2)
		program->sprite_pos.x += program->sprite.size.x;
	else if (key == 53)
		ft_close();
	
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->sprite_pos.x, program->sprite_pos.y);
	return (0);
}

int	ft_update(void *param)
{
	t_program	*program = (t_program *)param;
	static int	frame;
	frame++;
	if (frame == ANIMATION_FRAMES)
		program->sprite_pos.y += 1;
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		program->sprite_pos.y -= 1;
		frame = 0;
	}
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->sprite_pos.x, program->sprite_pos.y);
	return (0);
}