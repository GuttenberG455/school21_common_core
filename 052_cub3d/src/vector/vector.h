/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:17:56 by majacqua          #+#    #+#             */
/*   Updated: 2022/05/11 15:22:38 by majacqua         ###   ########.fr       */
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
 

#endif