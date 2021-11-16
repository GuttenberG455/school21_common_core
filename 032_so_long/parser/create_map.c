/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:01:52 by majacqua          #+#    #+#             */
/*   Updated: 2021/11/16 18:15:17 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_map.h"

void	clear_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->grid[i])
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	free(map);
}

int	create_map(char *map_src)
{
	t_map			*map;

	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return (0);
	map->grid = (char **) malloc(1000); // ИСПРАВИТЬ ЭТУ ХЕРНЮ
	get_grid(map_src, map->grid);
	check_map(map);
	print_map(map->grid);
	clear_map(map);
	return (1);
}
