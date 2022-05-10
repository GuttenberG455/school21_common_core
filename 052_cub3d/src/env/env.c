/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:37:51 by majacqua          #+#    #+#             */
/*   Updated: 2022/05/10 15:46:21 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = ft_zalloc(sizeof(t_map));
	map->no_path = NULL;
	map->so_path = NULL;
	map->we_path = NULL;
	map->ea_path = NULL;
	map->grid = NULL;
	map->floor_color = 0;
	map->ceiling_color = 0;
	map->width = 0;
	map->height = 0;
	return (map);
}

// DELETE
void	print_map(t_map *map)
{
	int i;
	
	printf("no_path -[%s]\n", map->no_path);
	printf("so_path -[%s]\n", map->so_path);
	printf("we_path -[%s]\n", map->we_path);
	printf("ea_path -[%s]\n", map->ea_path);
	printf("ceiling -[%d]\n", map->ceiling_color);
	printf("floor -[%d]\n", map->floor_color);
	printf("dimensions [%zux%zu]\n", map->width, map->height);
	if (map->grid)
	{
		i = 0;
		printf("        Grid map\n");
		while (i < map->height)
		{
			printf("%s\n", map->grid[i]);
			i++;
		}
	}
}