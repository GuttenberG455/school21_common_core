/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:45:02 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/14 14:26:34 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

// t_image	ft_new_image(void *mlx, int width, int height)
// {
// 	t_image img;

// 	img.reference = mlx_new_image(mlx, width, height);
// 	img.size.x = width;
// 	img.size.y = height;
// 	img.pixels = mlx_get_data_addr(img.reference, &img.bit_per_pixel, &img.line_size, &img.endian);

// 	return (img);
// }

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.reference, &img.bit_per_pixel, &img.line_size, &img.endian);
	return (img);
}