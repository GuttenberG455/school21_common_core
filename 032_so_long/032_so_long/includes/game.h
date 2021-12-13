/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:00:56 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/13 19:39:22 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <mlx.h>

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

typedef struct s_vector
{
	int	x;	
	int	y;	
} 		t_vector;

typedef struct s_window
{
	void 		*reference;
	t_vector	size;
}		t_window;

typedef struct s_image
{
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bit_per_pixel;
	int			line_size;
	int			byte_order;
}		t_image;

typedef struct s_program
{
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_vector	sprite_pos;
}		t_program;

t_window	ft_new_window(void *mlx, int widht, int height, char *name);

#endif