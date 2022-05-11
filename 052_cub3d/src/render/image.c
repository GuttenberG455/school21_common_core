/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:54:22 by majacqua          #+#    #+#             */
/*   Updated: 2022/05/11 11:56:02 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_img	*new_img(void *mlx)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	img->img_ptr = mlx_new_image(mlx, RES_X, RES_Y);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, \
		&img->bpp, &img->size_l, &img->endian);
	return (img);
}

t_img	*new_img_xpm(void *mlx, char *path)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	img->img_ptr = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, \
		&img->bpp, &img->size_l, &img->endian);
	return (img);
}