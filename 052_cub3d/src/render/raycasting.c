/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:29:44 by majacqua          #+#    #+#             */
/*   Updated: 2022/05/13 13:41:57 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

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
		// cast ray
		rays[i] = ray;
		rays[i]->angle = env->player->angle + cur_angle;
		cur_angle += step;
		i++;
	}
	// return (rays); // !!!
	return (NULL); 
}