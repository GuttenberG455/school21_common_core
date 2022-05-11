/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:57:40 by majacqua          #+#    #+#             */
/*   Updated: 2022/05/11 17:23:40 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void render(t_env *env)
{
	t_img	*frame;
	t_vect	**rays;
	int		i;

	frame = new_img(env->mlx);
	// rays = raycasting(env);
}