/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:03:52 by majacqua          #+#    #+#             */
/*   Updated: 2022/06/16 16:13:15 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vect	vect_new(float x, float y)
{
	t_vect	res;

	res.x = x;
	res.y = y;
	res.color = 0xFFFFFF;
	res.angle = 0;
	res.dist = sqrtf(x * x + y * y);
	return (res);
}

float	vect_len(t_vect vect)
{
	return (sqrtf(vect.x * vect.x + vect.y * vect.y));
}

t_vect	vect_add(t_vect vect1, t_vect vect2)
{
	t_vect	res;

	res.x = vect1.x + vect2.x;
	res.y = vect1.y + vect2.y;
	res.angle = vect1.angle;
	res.dist = vect_len(res);
	return (res);
}


t_vect	vect_sub(t_vect vect1, t_vect vect2)
{
	t_vect	res;

	res.x = vect1.x - vect2.x;
	res.y = vect1.y - vect2.y;
	res.angle = vect1.angle;
	res.dist = vect_len(res);
	return (res);
}

t_vect	vect_mul(t_vect vect, float mul)
{
	t_vect	res;

	res.x = vect.x * mul;
	res.y = vect.y * mul;
	res.angle = vect.angle;
	res.dist = vect_len(res);
	return (res);
}