/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:34:50 by majacqua          #+#    #+#             */
/*   Updated: 2022/06/22 12:38:45 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

char	get_wall_type(t_vect *ray)
{
	float	diff;

	ray->x = roundf(ray->x * 10000) / 10000;
	ray->y = roundf(ray->y * 10000) / 10000;
	if (ray->angle > PI * 2)
		ray->angle -= PI * 2;
	if (ray->angle < 0)
		ray->angle += PI * 2;
	diff = ray->x - (float)((int)ray->x);
	if (diff > 0 && (ray->angle > 0 && ray->angle <= PI))
		return (TYPE_NO);
	else if (diff > 0)
		return (TYPE_SO);
	else if (ray->angle > PI / 2 && ray->angle < 3 * PI / 2)
		return (TYPE_EA);
	else
		return (TYPE_WE);
}

void	put_col_img(t_column *col, t_vect *ray, t_img *img)
{
	float	step_tex;
	float	tex_y;
	int		tex_x;
	int		i;

	col->wall_height = col->bot - col->top;	// высота колонны
	step_tex = col->texture->height / col->wall_height;	// высота изображения
	tex_x = (int)roundf(col->texture->width * (ray->x - (float)((int)ray->x) \
		+ ray->y - (float)((int)ray->y)));	// x координаты в tex
	if (tex_x >= col->texture->width)
		tex_x = col->texture->width - 1;	// бесшовный переход текстур
	tex_y = 0;
	i = col->top;
	if (col->top < 0)
	{
		tex_y += step_tex * abs(col->top);	// y координаты в tex
		i = 0;
	}
	while (i < col->bot && i < RES_Y)
	{
		img->data[i * RES_X + col->x_pos] = get_pixel(col->texture, tex_x, tex_y);	// ставим по координатам пиксель с tex
		i++;
		tex_y += step_tex;
	}
}

void	render_column(t_env *env, t_img *img, t_vect *ray, int x_pos)
{
	t_column	column;
	int			type;
	int			i;

	type = get_wall_type(ray);	// тип стены, на которую указывает луч
	if (type == TYPE_NO)		// получаем изображение, по типу стены
		column.texture = env->map->no_img;
	else if (type == TYPE_SO)
		column.texture = env->map->so_img;
	else if (type == TYPE_EA)
		column.texture = env->map->ea_img;
	else if (type == TYPE_WE)
		column.texture = env->map->we_img;
	column.wall_height = RES_Y / (2 * cosf(env->player.angle - ray->angle) \
		* tan(VFOV) * ray->dist);	// получение высоты колонки
	column.top = (int)((RES_Y / 2) - column.wall_height);	// верхняя точка колонны
	column.bot = (int)((RES_Y / 2) + column.wall_height);	// нижняя точка колонны
	column.x_pos = x_pos;
	// printf("Column:type[%c], Top/Bot [%d:%d] Color_[%d]\n", type, column.top, column.bot, column.x_pos); // DEL
	put_col_img(&column, ray, img);	// нарисовать колонну изображения
	i = 0;
	while (i < column.top)
		put_pixel(img, x_pos, i++, env->map->ceiling_color);	// все, что выше, рисуем потолок
	i = column.bot;
	while (i < RES_Y)
		put_pixel(img, x_pos, i++, env->map->floor_color);		// все, что ниже, рисуем пол
}

void	render_walls(t_env *env, t_vect **rays, t_img *img)
{
	size_t	i;

	i = 0;
	while (i < RES_X)	// проходим по всему массиву лучей
	{
		render_column(env, img, rays[i], i);	// прорисовать колонну
		i++;
	}
}