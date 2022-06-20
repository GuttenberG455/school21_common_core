/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:54:34 by majacqua          #+#    #+#             */
/*   Updated: 2022/06/20 13:37:55 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
#define RENDER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "../const.h"
# include "../env/env.h"
# include "../vector/vector.h"

# include "../libftv2/libftv2.h"
# include "../minilibx/mlx.h"

typedef struct s_img	t_img;

struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
	int		width;
	int		height;
};

typedef struct s_raycast
{
	t_vect	player_vect;
	t_vect	map_check;
	t_vect	delta_dist;
	t_vect	side_dist;
	t_vect	step;
	t_vect	wall_hit;
	int		is_wall_found;
	float	distance;
}	t_raycast;

typedef struct s_column
{
	t_img	*texture;
	float	wall_height;
	int		top;
	int		bot;
	int		x_pos;
}	t_column;



void	render(t_env *env);
t_img	*new_img(void *mlx);
t_img	*new_img_xpm(void *mlx, char *path);
t_vect	**raycasting(t_env *env);
void	free_img(void *mlx, t_img *img);
void	render_walls(t_env *env, t_vect **rays, t_img *img);
void	put_pixel(t_img *img, int x, int y, int x_pos);
int		get_pixel(t_img *img, int x, int y);

// MINIMAP

# define COL_BLACK	0x000000
# define COL_GRAY	0x808080
# define COL_RED	0xFF8E8E
# define COL_ORANGE	0xFFA500
# define COL_YELLOW	0xFFF700
# define MINI_MAP_W	0.4

typedef struct s_rec
{
	int	x;
	int	y;
	int	width;
	int	height;
}	t_rec;

void	render_minimap(t_env *env, t_img *img);

#endif