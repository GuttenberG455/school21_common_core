/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:03:50 by majacqua          #+#    #+#             */
/*   Updated: 2022/05/10 15:49:46 by majacqua         ###   ########.fr       */
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
	while (i++ < 8) 
		ft_get_next_line(fd);
	str = ft_strtrim(ft_get_next_line(fd), "\n");
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


t_map *get_map(char *filename)
{
	t_map	*map;
	int		fd;

	map = init_map();
	get_dimensions(map, filename);
	fd = open(filename, O_RDONLY);	
	get_properties(map, fd);
	get_grid(map, fd);
	// check_assets_path(map); // !!! 
	close(fd);
	return (map);
}
