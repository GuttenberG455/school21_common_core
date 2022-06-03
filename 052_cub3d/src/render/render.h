/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:54:34 by majacqua          #+#    #+#             */
/*   Updated: 2022/06/03 15:56:05 by majacqua         ###   ########.fr       */
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
	t_vect	plr;
	t_vect	map_check;
	t_vect	unit_step;
	t_vect	step;
	t_vect	ray_lend;
	t_vect	intersection;
	int		found_wall;
	float	dist;
	float	max_dist;
}	t_raycast;

typedef struct s_column
{
	t_img	*texture;
	float	wall_height;
	int		top;
	int		bot;
	int		col;
}	t_column;



void render(t_env *env);
t_img	*new_img(void *mlx);
t_img	*new_img_xpm(void *mlx, char *path);
t_vect	**raycasting(t_env *env);
void	free_img(void *mlx, t_img *img);
void	render_walls(t_env *env, t_vect **rays, t_img *img);
void	put_pixel(t_img *img, int x, int y, int color);
int		get_pixel(t_img *img, int x, int y);

// MINIMAP

# define COL_WHITE	0xffffff
# define COL_BLACK	0x000000
# define COL_DGRAY	0x303030
# define COL_LGRAY	0x919191
# define COL_RED	0xFF7E7E
# define COL_YELLOW	0xFFF700
# define COL_BLUE	0x000d85
# define COL_GREEN	0x2d752e
# define MINI_MAP_W	0.4

typedef struct s_rec
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rec;

void	render_minimap(t_env *env, t_img *img, t_vect **rays);

#endif