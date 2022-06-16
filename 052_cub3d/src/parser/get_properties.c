/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_properties.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:43:12 by majacqua          #+#    #+#             */
/*   Updated: 2022/06/16 14:33:29 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t	get_word_count(char **array)
{
	int i;

	i = 0;
	if (!array)
		return (i);
	while (array[i])
		i++;
	return (i);	
}

int get_color(char *str)
{
	int color = 0;
	char **rgb;

	rgb = ft_split(str, ',');
	if (get_word_count(rgb) != 3)
		err_exit("Error!\nWrong rgb colors");
	if (ft_atoi(rgb[0]) > 255 || ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[2]) > 255 ||
		ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[1]) < 0 || ft_atoi(rgb[2]) < 0 ||
		(ft_atoi(rgb[0]) == 0 && rgb[0][0] != '0') ||
		(ft_atoi(rgb[1]) == 0 && rgb[1][0] != '0') ||
		(ft_atoi(rgb[2]) == 0 && rgb[2][0] != '0'))
			err_exit("Error!\nWrong colors");
	color = ft_atoi(rgb[0]);
	color = (color << 8) + ft_atoi(rgb[1]);
	color = (color << 8) + ft_atoi(rgb[2]);
	return color;
}

void add_property(t_map *map, char **prop)
{
	if (!prop || !prop[0] || !prop[1])
		err_exit("Error!\nWrong properties input");
	printf("prop:[%s][%s]\n", prop[0], prop[1]);
	if (ft_strlen(prop[0]) == 2 && ft_strncmp(prop[0], "NO", 2) == 0)
		map->no_path = prop[1];
	if (ft_strlen(prop[0]) == 2 && ft_strncmp(prop[0], "SO", 2) == 0)
		map->so_path = prop[1];
	if (ft_strlen(prop[0]) == 2 && ft_strncmp(prop[0], "WE", 2) == 0)
		map->we_path = prop[1];
	if (ft_strlen(prop[0]) == 2 && ft_strncmp(prop[0], "EA", 2) == 0)
		map->ea_path = prop[1];
	if (ft_strlen(prop[0]) == 1 && ft_strncmp(prop[0], "F", 1) == 0)
		map->floor_color = get_color(prop[1]);
	if (ft_strlen(prop[0]) == 1 && ft_strncmp(prop[0], "C", 1) == 0)
		map->ceiling_color = get_color(prop[1]);
}

void get_dimensions(t_map *map, int fd, char *first_lane)
{
	int i;
	char *str;
	
	str = first_lane; // первая строка
	map->width = ft_strlen(first_lane);
	i = 0;
	while (str)
	{
		if (ft_strlen(str) > map->width)
			map->width = ft_strlen(str);
		str = ft_strtrim(ft_get_next_line(fd), "\n"); 
		i++;
	}
	map->height = i; 
}

void get_properties(t_map *map, int fd)
{
	int i;
	char *str;
	
	i = 0;
	str = ft_strtrim(ft_get_next_line(fd), " \n\t"); // убираем табы и \n
	while (!is_filled(map) && str)
	{
		i++;
		if (ft_strlen(str))
			add_property(map, ft_split(str, ' '));
		str = ft_strtrim(ft_get_next_line(fd), " \n\t"); // убираем табы и \n
	}
	while (ft_strlen(str) == 0)
	{
		str = ft_strtrim(ft_get_next_line(fd), " \n\t");
		i++;
	}
	map->num_start_grid = i;
	get_dimensions(map, fd, str);
	printf("Start of map - %d\n", map->num_start_grid);
}