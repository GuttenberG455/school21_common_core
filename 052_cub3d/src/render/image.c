/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:54:22 by majacqua          #+#    #+#             */
/*   Updated: 2022/06/03 13:45:16 by majacqua         ###   ########.fr       */
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

void	free_img(void *mlx, t_img *img)
{
	mlx_destroy_image(mlx, img->img_ptr);
	free(img);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	if (x < RES_X && y < RES_Y && x >= 0 && y >= 0)
		img->data[y * RES_X + x] = color;
}

int	get_pixel(t_img *img, int x, int y)
{
	if (x >= img->width || y >= img->height || x < 0 || y < 0)
		return (0);
	return (img->data[y * img->width + x]);
}