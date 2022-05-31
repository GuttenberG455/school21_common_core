/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:17:56 by majacqua          #+#    #+#             */
/*   Updated: 2022/05/31 19:36:52 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

# include <math.h>

typedef struct s_vect
{
	float	x;
	float	y;
	float	dist;
	float	angle;
	int		color;
} t_vect;

t_vect	vect_new(float x, float y);
float	vect_len(t_vect vect);
t_vect	vect_add(t_vect vect1, t_vect vect2);
t_vect	vect_sub(t_vect vect1, t_vect vect2);
t_vect	vect_mul(t_vect vect, float mul);
void	vect_norm(t_vect *vect);
t_vect	vect_rot(t_vect vect, float angle);
float	vec_scal_prod(float angle, t_vect projected);


#endif