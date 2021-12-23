/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:44:39 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/23 18:43:24 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <mlx.h>
// # include <stdio.h>
# include "../libft/libft.h"

# ifndef INT_MAX
#  define INT_MAX 2147483647 
# endif

typedef struct s_vector
{
	int	x;	
	int	y;	
}		t_vector;

typedef struct s_window
{
	void		*ptr;		
	t_vector	size;			
}		t_window;

typedef struct s_image
{
	void		*ptr;
	t_vector	size;
	t_vector	pos;
	char		*pixels;
	int			bit_per_pixel;
	int			line_size;
	int			endian;
}		t_image;

typedef struct s_map {
	char			**grid;
	int				height;
	int				width;
	int				status;
	unsigned int	player_count;
	unsigned int	exit_count;
	unsigned int	coins_count;
}	t_map;

typedef struct s_player
{
	t_vector	cur_pos;
	int			step_count;
}		t_player;

typedef struct s_prog
{
	void		*mlx;
	t_window	window;
	t_vector	sprite_pos;
	t_image		sprite;
	t_player	player;
	t_map		map;
}		t_prog;

// void		printf_map_grid(t_prog *prog);

void		get_dimensions(t_prog *prog, char **argv);
void		get_map_grid(t_prog *prog, char *file_name);
int			check_map_grid(t_prog *prog);
void		get_map_status(t_map *map);
void		get_counts(t_map *map);

int			ft_close(char *text);
t_window	ft_new_window(void *mlx, t_map map);
t_image		ft_new_sprite(void *mlx, char *path);
int			ft_input(int key, void *param);

void		draw_map(t_prog prog);
void		draw_sprite_wall(t_prog prog, int i, int j);
void		draw_sprite_coins(t_prog prog, int i, int j);
void		draw_sprite_exit(t_prog prog, int i, int j);
void		draw_sprite_player(t_prog prog, int i, int j);
void		draw_sprite_enemy(t_prog prog, int i, int j);
void		draw_sprite_ground(t_prog prog, int i, int j);

void		player_move_up(t_prog *prog);
void		player_move_left(t_prog *prog);
void		player_move_down(t_prog *prog);
void		player_move_right(t_prog *prog);

void		make_player_move(t_prog *prog, t_vector old_pos, t_vector next_pos);
void		map_get_player_pos(t_prog *prog);
int			map_check_gameover(t_prog *prog, t_vector next_pos);

#endif