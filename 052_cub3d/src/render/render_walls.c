/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:34:50 by majacqua          #+#    #+#             */
/*   Updated: 2022/06/03 14:04:27 by majacqua         ###   ########.fr       */
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
	if (diff == 0 && (ray->angle > PI / 2 && ray->angle < 3 * PI / 2))
		return (TYPE_WE);
	else if (diff == 0)
		return (TYPE_EA);
	else if (ray->angle > 0 && ray->angle <= PI)
		return (TYPE_NO);
	else
		return (TYPE_SO);
}

void	put_column(t_column *col, t_vect *ray, t_img *img)
{
	int		i;
	float	i_tex;
	float	step_tex;
	int		tex_col;

	col->wall_height = col->bot - col->top;
	step_tex = col->texture->height / col->wall_height;
	tex_col = (int)roundf(col->texture->width * (ray->x - (float)((int)ray->x) \
		+ ray->y - (float)((int)ray->y)));
	if (tex_col >= col->texture->width)
		tex_col = col->texture->width - 1;
	i_tex = 0;
	i = col->top;
	if (col->top < 0)
	{
		i_tex += step_tex * abs(col->top);
		i = 0;
	}
	while (i < col->bot && i < RES_Y)
	{
		img->data[i * RES_X + col->col] = \
			get_pixel(col->texture, tex_col, i_tex);
		i++;
		i_tex += step_tex;
	}
}

void	render_column(t_env *env, t_img *img, t_vect *ray, int col)
{
	t_column	column;
	int			type;
	int			i;

	type = get_wall_type(ray);
	if (type == TYPE_NO)
		column.texture = env->map->no_img;
	else if (type == TYPE_SO)
		column.texture = env->map->so_img;
	else if (type == TYPE_EA)
		column.texture = env->map->ea_img;
	else if (type == TYPE_WE)
		column.texture = env->map->we_img;
	column.wall_height = RES_Y / (2 * cosf(env->player.angle - ray->angle) \
		* tan(VFOV) * ray->dist);
	column.top = (int)((RES_Y / 2) - column.wall_height);
	column.bot = (int)((RES_Y / 2) + column.wall_height);
	column.col = col;
	i = 0;
	while (i < column.top)
		put_pixel(img, col, i++, env->map->ceiling_color);
	i = column.bot;
	while (i < RES_Y)
		put_pixel(img, col, i++, env->map->floor_color);
	put_column(&column, ray, img);
}

void	render_walls(t_env *env, t_vect **rays, t_img *img)
{
	size_t	i;

	i = 0;
	while (i < RES_X)
	{
		render_column(env, img, rays[i], i);
		i++;
	}
}