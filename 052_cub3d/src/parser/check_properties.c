/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_properties.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:49:58 by majacqua          #+#    #+#             */
/*   Updated: 2022/07/25 14:34:39 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_filled(t_map *map)
{
	if (!map->no_path || !map->so_path || !map->we_path || !map->ea_path)
		return (0);
	if (map->ceiling_color == -1 || map->floor_color == -1)
		return (0);
	return (1);
}

void	check_assets_path(t_map *map)
{
	int	fd;

	fd = open(map->no_path, O_RDONLY);
	if (fd == -1)
		err_exit("Wrong asset path");
	close(fd);
	fd = open(map->so_path, O_RDONLY);
	if (fd == -1)
		err_exit("Wrong asset path");
	close(fd);
	fd = open(map->ea_path, O_RDONLY);
	if (fd == -1)
		err_exit("Wrong asset path");
	close(fd);
	fd = open(map->we_path, O_RDONLY);
	if (fd == -1)
		err_exit("Wrong asset path");
	close(fd);
}
