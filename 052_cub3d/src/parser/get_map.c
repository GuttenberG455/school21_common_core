/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:03:50 by majacqua          #+#    #+#             */
/*   Updated: 2022/06/20 12:54:20 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char *get_grid_line(t_map *map, char *str)
{
	char *res;
	unsigned int i;
	
	i = 0;
	res = ft_zalloc(map->width + 1);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	while (i < map->width)
	{
		res[i] = ' ';
		i++;
	}
	return (res);
}

void get_grid(t_map *map, int fd)
{
	unsigned int i;
	unsigned int j;
	
	i = 0;
	map->grid = ft_zalloc(sizeof(char *) * map->height + 1);
	while (i < map->height)
	{
		map->grid[i] = get_grid_line(map, ft_strtrim(ft_get_next_line(fd), "\n")); // получаем строку поля
		j = 0;
		while (map->grid[i][j])
		{
			if (!ft_strchr(" 01SNWE", map->grid[i][j])) // если неправильный символ в поле
			{
				printf("_+%d+_", j);
				err_exit("Error!\nWrong symbols in grid");
			}
			j++;
		}
		i++;
	}
}

int check_neighbors(t_map *map, unsigned int i, unsigned int j)
{
	if (i == 0 || j == 0) 
		if (ft_strchr("0SNWE", map->grid[i][j]))
			return (1);
	if (i == map->height - 1 || j == map->width - 1) 
		if (ft_strchr("0SNWE", map->grid[i][j]))
			return (1);
	if (!ft_strchr("01SNWE", map->grid[i-1][j]) ||
		!ft_strchr("01SNWE", map->grid[i+1][j]) || 
		!ft_strchr("01SNWE", map->grid[i][j-1]) ||
		!ft_strchr("01SNWE", map->grid[i][j+1]))
			return (1);
	return (0);
}

void	check_grid_borders(t_map *map)
{
	size_t i;
	size_t j;
	
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < ft_strlen(map->grid[i]))
		{
			if (ft_strchr("0SNWE", map->grid[i][j])) 
			{
				if (check_neighbors(map, i, j)) // проверка соседних клеток
				{
					printf("Err at [%zu:%zu] symb{%s}\n", i, j, map->grid[i]);
					err_exit("Error!\nBad borders");
				}
			}
			j++;
		}
		i++;		
	}
}

void	skip_unuseful_lines(t_map *map, int fd)
{
	int i;

	i = 0;
	while (i++ < map->num_start_grid) // скипаем до поля
		ft_get_next_line(fd);
}

t_map *get_map(char *filename)
{
	t_map	*map;
	int		fd;

	map = init_map();	// инициализации карты
	fd = open(filename, O_RDONLY);
	get_properties(map, fd); // получение данных
	close(fd);
	fd = open(filename, O_RDONLY);
	skip_unuseful_lines(map, fd);
	get_grid(map, fd);	// получение поля
	close(fd);
	check_grid_borders(map); // проверка границ поля
	check_assets_path(map);	// проверка путей ассетов
	return (map);
}
