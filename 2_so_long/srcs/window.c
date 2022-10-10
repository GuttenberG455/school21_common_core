/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:56:35 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/23 19:24:28 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include <unistd.h>

int	ft_close(char *text)
{
	ft_putstr_fd(text, 1);
	exit(0);
}

t_window	ft_new_window(void *mlx, t_map map)
{
	t_window	window;

	window.size.x = map.width * 32;
	window.size.y = map.height * 32;
	window.ptr = mlx_new_window(mlx, window.size.x, window.size.y,
			"Dankest Dungeon");
	mlx_hook(window.ptr, 17, 0, ft_close, 0);
	return (window);
}
