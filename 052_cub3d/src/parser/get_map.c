/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:03:50 by majacqua          #+#    #+#             */
/*   Updated: 2022/06/14 17:54:47 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void get_dimensions(t_map *map, char *filename)
{
	int fd;
	int i;
	char *str;

	fd = open(filename, O_RDONLY);
	i = 0;
	while (i++ < 8) // скипаем лишнее
		ft_get_next_line(fd);
	str = ft_strtrim(ft_get_next_line(fd), "\n"); // первая строка
	map->width = ft_strlen(str);
	i = 0;
	while (str)
	{
		if (ft_strlen(str) > map->width)
			map->width = ft_strlen(str);
		str = ft_strtrim(ft_get_next_line(fd), "\n"); 
		i++;
	}
	map->height = i; 
	close(fd);
}

void	check_assets_path(t_map *map)
{
	int	fd;

	fd = open(map->no_path, O_RDONLY);
	if (fd == -1)
		exit_txt("Wrong asset path");
	close(fd);
	fd = open(map->so_path, O_RDONLY);
	if (fd == -1)
		exit_txt("Wrong asset path");
	close(fd);
	fd = open(map->ea_path, O_RDONLY);
	if (fd == -1)
		exit_txt("Wrong asset path");
	close(fd);
	fd = open(map->we_path, O_RDONLY);
	if (fd == -1)
		exit_txt("Wrong asset path");
	close(fd);
}

void get_grid(t_map *map, int fd)
{
	int i;
	
	i = 0;
	map->grid = ft_zalloc(sizeof(char *) * map->height + 1);
	while (i < map->height)
	{
		map->grid[i] = ft_strtrim(ft_get_next_line(fd), "\n"); // получаем строку поля
		i++;
	}
}

t_map *get_map(char *filename)
{
	t_map	*map;
	int		fd;

	map = init_map();	// инициализации карты
	get_dimensions(map, filename); // получение ширины и высоты
	fd = open(filename, O_RDONLY);	
	get_properties(map, fd); // получение данных
	get_grid(map, fd);	// получение поля
	check_assets_path(map);	// проверка путей ассетов
	close(fd);
	return (map);
}
