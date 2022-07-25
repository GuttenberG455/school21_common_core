/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:29:44 by majacqua          #+#    #+#             */
/*   Updated: 2022/07/25 14:37:16 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"


void	init_ray(t_env *env, t_raycast *rc, t_vect dir)
{
	rc->player_vect = vect_new(env->player.x / env->size, env->player.y / env->size); // позиция игрока на поле
	rc->delta_dist = vect_new(fabs(1.0f / dir.x), fabs(1.0f / dir.y)); // шаг между границами для X, где dist(Y) = 1
	rc->map_check.x = (int)rc->player_vect.x; // текущий player_vect в (int)
	rc->map_check.y = (int)rc->player_vect.y;
	if (dir.x < 0) // distance from the ray starting position to the first side to the left / right
	{
		rc->step.x = -1.0f;
		rc->side_dist.x = (rc->player_vect.x - rc->map_check.x) * rc->delta_dist.x;
	}
	else
	{
		rc->step.x = 1.0f;
		rc->side_dist.x = (rc->map_check.x + 1 - rc->player_vect.x) * rc->delta_dist.x;
	}
	if (dir.y < 0) // distance from the ray starting position to the first side to the above / below,
	{
		rc->step.y = -1.0f;
		rc->side_dist.y = (rc->player_vect.y - rc->map_check.y) * rc->delta_dist.y;
	}
	else
	{
		rc->step.y = 1.0f;
		rc->side_dist.y = (rc->map_check.y + 1 - rc->player_vect.y) * rc->delta_dist.y;
	}
}

void	find_wall(t_env *env, t_raycast *rc)
{
	while (!rc->is_wall_found) 
	{
		if (rc->side_dist.x < rc->side_dist.y) // двигаемся по оси x
		{
			rc->map_check.x += rc->step.x;
			rc->distance = rc->side_dist.x;
			rc->side_dist.x += rc->delta_dist.x;
		}
		else // по оси y
		{
			rc->map_check.y += rc->step.y;
			rc->distance = rc->side_dist.y;
			rc->side_dist.y += rc->delta_dist.y;
		}
		if (ft_strchr(" 1", env->map->grid[(int)rc->map_check.y][(int)rc->map_check.x])) // !!!
			rc->is_wall_found = 1; // флаг нахождения стены
	}
}

t_vect	get_ray(t_env *env, t_vect dir)
{
	t_raycast	rc; 	// две структуры
	t_vect		wall_hit;

	ft_bzero(&rc, sizeof(t_raycast));		// обнуляем
	ft_bzero(&wall_hit, sizeof(t_vect));	// 
	init_ray(env, &rc, dir);
	find_wall(env, &rc);
	if (rc.is_wall_found == 1) // если нашли стену
	{
		wall_hit = vect_add(rc.player_vect, vect_mul(dir, rc.distance)); // позиция прорисованной точки попадания луча в стену
		wall_hit.color = 0;	// цвет 0
		wall_hit.dist = rc.distance;	// длина - расстояние
	}
	return (wall_hit);	// возвращаем точку попадания
}

t_vect	**raycasting(t_env *env)
{
	t_vect	**rays;
	t_vect	*ray;
	int		i;
	float	step;
	float	cur_angle;

	rays = (t_vect **)malloc(sizeof(t_vect *) * RES_X); // создаем двумерный массив векторов, с шириной экрана
	step = (float)FOV / RES_X;	// шаг ФОВ / разрешение (0.000818)
	cur_angle = -FOV / 2; // начинаем слева -> направо
	i = 0;
	while (i < RES_X) // проходим все по ширине
	{
		ray = malloc(sizeof(t_vect)); // один вектор
		*ray = get_ray(env, vect_rot(vect_new(-1.0f, 0.0f), env->player.angle + cur_angle)); // получаем луч попадания в стену
		ray->angle = env->player.angle + cur_angle; // угол луча
		rays[i] = ray; // добавляем созданный вектор в наш массив
		cur_angle += step; // идем дальше
		i++;	// идем дальше
	}
	return (rays);
}
