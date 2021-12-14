/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:00:56 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/14 18:53:28 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <mlx.h>
# include "game.h"
# include "get_map.h"

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
	void 		*reference;		//указатель на окно
	t_vector	size;			//размер изображения
}		t_window;

typedef struct s_image
{
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bit_per_pixel;
	int			line_size;
	int			endian;
}		t_image;

typedef struct s_player
{
	t_vector	cur_pos;
}		t_player;

typedef struct s_program
{
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_vector	sprite_pos;
	t_player	player;
	t_map		*map;
}		t_program;

t_window	ft_new_window(void *mlx, t_map *map);
t_image		ft_new_image(void *mlx, int width, int height);
t_image		ft_new_sprite(void *mlx, char *path);
int			ft_close();
int			ft_input(int key, void *param);
int			ft_update(void *param);

void	draw_map(t_program program);
void	draw_sprite_wall(t_program program, int i, int j);
void	draw_sprite_coins(t_program program, int i, int j);
void	draw_sprite_exit(t_program program, int i, int j);

#endif