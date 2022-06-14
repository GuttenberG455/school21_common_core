/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:57:40 by majacqua          #+#    #+#             */
/*   Updated: 2022/06/14 18:16:15 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void render(t_env *env)
{
	t_img	*frame;
	t_vect	**rays;
	int		i;

	i = 0;
	frame = new_img(env->mlx); // создаем новое изображение
	rays = raycasting(env);
	render_walls(env, rays, frame); // стены
	render_minimap(env, frame); // миникарта
	mlx_put_image_to_window(env->mlx, env->win, frame->img_ptr, 0, 0);
	free_img(env->mlx, frame); // очищаем изображение
	while (i < RES_X)
		free(rays[i++]);
	free(rays);
	
}