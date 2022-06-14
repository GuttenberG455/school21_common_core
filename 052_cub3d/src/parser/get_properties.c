/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_properties.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:43:12 by majacqua          #+#    #+#             */
/*   Updated: 2022/06/14 17:54:24 by majacqua         ###   ########.fr       */
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
		map->floor_color = get_color(prop[1]); // получаем цвет в виде int
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
		str = ft_strtrim(ft_get_next_line(fd), " \n\t"); // убираем табы и \n
		if (count != 4 && count != 7) // пропуск пустых строк
			add_property(map, ft_split(str, ' '), count); //  добавляем свойство
		count++;
	}
}
