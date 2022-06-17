/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:51:25 by majacqua          #+#    #+#             */
/*   Updated: 2022/06/17 16:48:52 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render_player(t_env *env, t_img *img, float scale)
{
	size_t	pl_size;
	size_t	i;
	size_t	j;
	size_t	dx;
	size_t	dy;

	pl_size = env->size / 2;
	i = env->player.x - pl_size;
	while (i < env->player.x + pl_size)
	{
		j = env->player.y - pl_size;
		while (j < env->player.y + pl_size)
		{
			dx = i - env->player.x;
			dy = j - env->player.y;
			if (dx * dx + dy * dy < pl_size * pl_size)
				put_pixel(img, i * scale, j * scale, COL_YELLOW);
			j++;
		}
		i++;
	}
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
				put_pixel(img, i, j, COL_GRAY);
			else
				put_pixel(img, i, j, COL_RED);
			j++;
		}
		i++;
	}
}

float	get_scale_minimap(t_env *env)
{
	int	max_width;

	if (env->size < 15)
		max_width = (int)floorf(RES_X * MINI_MAP_W);
	else
		max_width = (int)floorf(RES_X * MINI_MAP_W / 2);
	while (max_width % env->map->width != 0)
		max_width--;
		
	return ((float)max_width / (float)RES_X); // масштаб миникарты
}

void	render_minimap(t_env *env, t_img *img)
{
	t_rec	rec;
	float	scale;
	size_t	i;
	size_t	j;

	i = 0;
	scale = get_scale_minimap(env);	// получить масштаб миникарты
	while (i < env->map->height)	
	{
		j = 0;
		while (j < ft_strlen(env->map->grid[i]))
		{
			rec.x = (int)(j * env->size * scale);
			rec.y = (int)(i * env->size * scale);
			rec.width = (int)(rec.x + env->size * scale);	// размер миникарты по ширине
			rec.height = (int)(rec.y + env->size * scale);	// по высоте
			if (!ft_strchr("1 ", env->map->grid[i][j]))		// если, не граница, то рисуем
				draw_rec(img, &rec);	// нарисовать прямоугольник
			j++;
		}
		i++;
	}
	render_player(env, img, scale);	// нарисовать положение игрока
}
