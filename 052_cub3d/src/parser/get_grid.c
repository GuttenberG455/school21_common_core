/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:43:12 by majacqua          #+#    #+#             */
/*   Updated: 2022/05/10 15:34:39 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int get_color(char *str)
{
	int color = 0;
	char **rgb;

	rgb = ft_split(str, ',');
	color = ft_atoi(rgb[0]);
	color = (color << 8) + ft_atoi(rgb[1]);
	color = (color << 8) + ft_atoi(rgb[2]);
	return color;
}

void add_property(t_map *map, char **prop, int count)
{
	if (count == 0) 
		map->no_path = prop[1];
	if (count == 1) 
		map->so_path = prop[1];
	if (count == 2) 
		map->we_path = prop[1];
	if (count == 3) 
		map->ea_path = prop[1];
	if (count == 5)
		map->floor_color = get_color(prop[1]);
	if (count == 6)
		map->ceiling_color = get_color(prop[1]);
}

void get_properties(t_map *map, int fd)
{
	int		count;
	char	*str;

	count = 0;
	while (count < 8)
	{
		str = ft_strtrim(ft_get_next_line(fd), " \n\t");
		if (count != 4 && count != 7)
			add_property(map, ft_split(str, ' '), count);
		count++;
	}
}

void get_grid(t_map *map, int fd)
{
	int i;
	
	i = 0;
	map->grid = ft_zalloc(sizeof(char *) * map->height + 1);
	while (i < map->height)
	{
		map->grid[i] = ft_strtrim(ft_get_next_line(fd), "\n");
		i++;
	}
}