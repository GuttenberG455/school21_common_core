/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:51:25 by majacqua          #+#    #+#             */
/*   Updated: 2022/06/03 16:00:06 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

// void	render_rays(t_env *env, t_img *img, t_vect **rays, float scale)
// {
// 	float	size;
// 	size_t	i;
// 	t_vect	vec;

// 	i = 0;
// 	size = (RES_X * scale) / env->map->width;
// 	while (i < RES_X - 1)
// 	{
// 		vec.x = rays[i]->x * size;
// 		vec.y = rays[i]->y * size;
// 		put_pixel(img, (int)(vec.x), (int)(vec.y), COL_YELLOW);
// 		i += 8;
// 	}
// }

void	render_player(t_env *env, t_img *img, float scale)
{
	size_t	pl_size;
	size_t	i;
	size_t	j;
	size_t	dx;
	size_t	dy;

	pl_size = env->size / 3;
	i = env->player.x - pl_size;
	while (i < env->player.x + pl_size)
	{
		j = env->player.y - pl_size;
		while (j < env->player.y + pl_size)
		{
			dx = i - env->player.x;
			dy = j - env->player.y;
			if (dx * dx + dy * dy < pl_size * pl_size)
				put_pixel(img, i * scale, j * scale, COL_GREEN);
			j++;
		}
		i++;
	}
	put_pixel(img, env->player.x * scale, env->player.y * scale, COL_RED);
}

void	draw_rec(t_img *img, t_rec *rec)
{
	int	i;
	int	j;

	i = rec->x;
	while (i < rec->width + 1)
	{
		j = rec->y;
		while (j < rec->height + 1)
		{
			if (i == rec->x || j == rec->y || \
				i == rec->width || j == rec->height)
				put_pixel(img, i, j, COL_DGRAY);
			else
				put_pixel(img, i, j, rec->color);
			j++;
		}
		i++;
	}
}

float	calc_scale(t_env *env)
{
	int	max_width;

	max_width = (int)floorf(RES_X * MINI_MAP_W);
	while (max_width % env->map->width != 0)
		max_width--;
	return ((float)max_width / (float)RES_X);
}

void	render_minimap(t_env *env, t_img *img, t_vect **rays)
{
	t_rec	rec;
	float	scale;
	size_t	i;
	size_t	j;

	i = 0;
	scale = calc_scale(env);
	while (i < env->map->height)
	{
		j = 0;
		while (j < env->map->width)
		{
			rec.x = (int)(j * env->size * scale);
			rec.y = (int)(i * env->size * scale);
			rec.width = (int)(rec.x + env->size * scale);
			rec.height = (int)(rec.y + env->size * scale);
			rec.color = COL_LGRAY;
			if (!ft_strchr(" 1", env->map->grid[i][j]))
				draw_rec(img, &rec);
			j++;
		}
		i++;
	}
	render_player(env, img, scale);
	// render_rays(env, img, rays, scale);
}
