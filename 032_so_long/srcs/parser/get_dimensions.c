/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:01:42 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/15 20:08:09 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.h"
#include "../../includes/grid.h"

int	check_dimensions(t_map *map)
{
	int	i;

	i = 0;
	while (map->grid[i])
	{
		if (ft_strlen(map->grid[i]) != map->width)
			return (1);
		i++;
	}
	return (0);
}

int	get_dimensions(char *file, t_map *map)
{
	int		fd;
	int		i;
	int		byte_count;
	char	ch;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	byte_count = 1;
	map->height = 0;
	map->width = 0;
	i = 0;
	while (byte_count)
	{
		byte_count = read(fd, &ch, 1);
		if ((ch == '\n') || (byte_count == 0))
		{
			map->height++;
			if (i != map->width)
			{
				printf("PIZDEC - %d\n", i);
				close(fd);
				return (1);
			}
			i = 0;
			continue ;
		}
		if (!byte_count)
			break ;
		if (map->height == 0)
			map->width++;
		i++;
	}
	close(fd);
	return (0);
}
