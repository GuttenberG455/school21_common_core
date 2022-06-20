/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:03:50 by majacqua          #+#    #+#             */
/*   Updated: 2022/06/14 12:26:56 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vect_norm(t_vect *vect)
{
	float	l;

	l = vect_len(*vect);
	if (l != 0)
	{
		vect->x /= l;
		vect->y /= l;
	}
}

t_vect	vect_rot(t_vect vect, float angle)
{
	t_vect	res;

	res.x = vect.x * cos(angle) + vect.y * -sin(angle);
	res.y = vect.x * sin(angle) + vect.y * cos(angle);
	return (res);
}

float	deg_to_rad(float deg)
{
	return (deg * 3.14f / 180.0f);
}

float	vec_scal_prod(float angle, t_vect projected)
{
	float	alfa;

	alfa = deg_to_rad(angle) - deg_to_rad(projected.angle);
	return (projected.dist * cosf(alfa));
}