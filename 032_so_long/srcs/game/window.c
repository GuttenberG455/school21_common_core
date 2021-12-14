/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:15:12 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/14 14:39:36 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

int	ft_close()
{
	exit(0);
}

int	get_window_width(t_map *map)
{
	int	width;
	int i;

	i = 0;
	while (map->grid[0][i])
		i++;
	return (i);
}

int	get_window_height(t_map *map)
{
	int height;
	int i;

	i = 0;
	while (map->grid[i])
		i++;
	return (i);
}

t_window	ft_new_window(void *mlx, t_map *map)
{
	t_window	window;
	int			width_pix;
	int			height_pix;
	
	width_pix = get_window_width(map) * 32;
	height_pix = get_window_height(map) * 32;
	printf("%dx%d - window\n", width_pix, height_pix);
	window.reference = mlx_new_window(mlx, width_pix, height_pix, "Dankest Dungeon");
	window.size.x = width_pix;
	window.size.y = height_pix;

	mlx_hook(window.reference, 17, 0, ft_close, 0);
	
	return (window);
}

