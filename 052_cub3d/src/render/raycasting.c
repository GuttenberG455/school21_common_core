/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:29:44 by majacqua          #+#    #+#             */
/*   Updated: 2022/06/03 14:20:17 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"


void	init_ray(t_env *env, t_raycast *rc, t_vect dir)
{
	rc->plr = vect_new(env->player.x / env->size, env->player.y / env->size);
	rc->unit_step = vect_new(fabs(1.0f / dir.x), fabs(1.0f / dir.y));
	rc->map_check.x = (int)rc->plr.x;
	rc->map_check.y = (int)rc->plr.y;
	if (dir.x < 0)
	{
		rc->step.x = -1.0f;
		rc->ray_lend.x = (rc->plr.x - rc->map_check.x) * rc->unit_step.x;
	}
	else
	{
		rc->step.x = 1.0f;
		rc->ray_lend.x = (rc->map_check.x + 1 - rc->plr.x) * rc->unit_step.x;
	}
	if (dir.y < 0)
	{
		rc->step.y = -1.0f;
		rc->ray_lend.y = (rc->plr.y - rc->map_check.y) * rc->unit_step.y;
	}
	else
	{
		rc->step.y = 1.0f;
		rc->ray_lend.y = (rc->map_check.y + 1 - rc->plr.y) * rc->unit_step.y;
	}
}

void	cast_ray(t_env *env, t_raycast *rc)
{
	while (!rc->found_wall && rc->dist < rc->max_dist)
	{
		if (rc->ray_lend.x < rc->ray_lend.y)
		{
			rc->map_check.x += rc->step.x;
			rc->dist = rc->ray_lend.x;
			rc->ray_lend.x += rc->unit_step.x;
		}
		else
		{
			rc->map_check.y += rc->step.y;
			rc->dist = rc->ray_lend.y;
			rc->ray_lend.y += rc->unit_step.y;
		}
		if (rc->map_check.x >= 0 && rc->map_check.y >= 0 && rc->map_check.x < env->map->width && rc->map_check.y < env->map->height)
		{
			if (ft_strchr(" 1", env->map->grid[(int)rc->map_check.y][(int)rc->map_check.x]))
				rc->found_wall = 1;
		}
	}
}

t_vect	get_ray(t_env *env, t_vect dir)
{
	t_raycast	rc;
	t_vect		intersection;

	ft_bzero(&rc, sizeof(t_raycast));
	ft_bzero(&intersection, sizeof(t_vect));
	rc.max_dist = 50000.0f;
	init_ray(env, &rc, dir);
	cast_ray(env, &rc);
	if (rc.found_wall == 1)
	{
		intersection = vect_add(rc.plr, vect_mul(dir, rc.dist));
		intersection.color = 0;
		intersection.dist = rc.dist;
	}
	return (intersection);
}

t_vect **raycasting(t_env *env)
{
	t_vect	**rays;
	t_vect	*ray;
	int		i;
	float	step;
	float	cur_angle;

	rays = (t_vect **)malloc(sizeof(t_vect *) * RES_X);
	step = (float)FOV / RES_X;
	cur_angle = -FOV / 2;
	i = 0;
	while (i < RES_X)
	{
		ray = malloc(sizeof(t_vect));
		*ray = get_ray(env, vect_rot(vect_new(-1.0f, 0.0f), env->player.angle + cur_angle));
		rays[i] = ray;
		rays[i]->angle = env->player.angle + cur_angle;
		cur_angle += step;
		i++;
	}
	return (rays); 
}