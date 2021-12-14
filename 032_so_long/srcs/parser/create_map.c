/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:01:52 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/14 18:55:46 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_map.h"
#include "../../includes/get_grid.h"

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

t_map	*create_map(char *map_src)
{
	t_map			*map;

	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return (0);
	if (get_dimensions(map_src, map))
	{
		ft_putstr("Error\nIncorrect map: Wrong dimensions");
		free(map);
		return (0);
	}	
	map->grid = (char **) malloc(map->height + 1);
	get_grid(map_src, map->grid);
	check_map(map);
	// print_map(map->grid);
	return (map);
	// clear_map(map);
	// return (0);
}
