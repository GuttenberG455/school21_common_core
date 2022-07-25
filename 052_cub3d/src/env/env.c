/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:37:51 by majacqua          #+#    #+#             */
/*   Updated: 2022/07/25 14:33:27 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = ft_zalloc(sizeof(t_map));	// выделяем память, если не выделилась, то внутри обработка
	map->no_path = NULL;
	map->so_path = NULL;
	map->we_path = NULL;
	map->ea_path = NULL;
	map->grid = NULL;
	map->floor_color = -1;
	map->ceiling_color = -1;
	map->width = 0;
	map->height = 0;
	map->num_start_grid = 0;
	return (map);
}

float	get_angle(char ch)
{
	if (ch == 'N')
		return (PI / 2);
	if (ch == 'S')
		return ((3 * PI) / 2);
	if (ch == 'W')
		return (0);
	if (ch == 'E')
		return (PI);
	return (0);
}

t_vect	create_player(t_map *map, t_env *env)
{
	t_vect			player;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	player.x = -1;
	while (i < map->height)
	{
		j = 0;
		while (j < ft_strlen(env->map->grid[i]))
		{
			if (ft_strchr("SNWE", map->grid[i][j]) && player.x != -1)
				err_exit("Error!/n Two players on the map");
			if (ft_strchr("SNWE", map->grid[i][j]))
			{
				player.y = i * env->size + env->size / 2; // позиция игрока сразу в координатах
				player.x = j * env->size + env->size / 2;
				player.angle = get_angle(map->grid[i][j]); // узнать в какую сторон смотрит игрок изначально
				map->grid[i][j] = '0'; // Обнуляем позицию
			}
			j++;
		}
		i++;
	}
	if (player.x == -1)
		err_exit("Error!/n No player's position on the map");
	return (player);
}

// DELETE
void	print_map(t_map *map)
{
	unsigned int i;
	
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

// DELETE
void	print_player(t_vect player)
{
	printf("Player\t");
	printf("Pos:[%f][%f] Angle = %f\n", player.x, player.y, player.angle);
}

void	print_vector(t_vect vect, char *str)
{
	printf("Vect - %s\n", str);
	printf("Coors:[%f][%f] Angle = [%f] Dist = [%f] Color = [%d]\n", vect.x, vect.y, vect.dist, vect.angle, vect.color);
}