/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:33:56 by majacqua          #+#    #+#             */
/*   Updated: 2021/11/16 19:02:20 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.h"
#include "get_grid.h"

void	print_error(int status)
{
	if (status == 1)
		ft_putstr("Error\nIncorrect map: No borders");
	else if (status == 20)
		ft_putstr("Error\nIncorrect map: No player");
	else if (status == 21)
		ft_putstr("Error\nIncorrect map: Two or more players");
	else if (status == 30)
		ft_putstr("Error\nIncorrect map: No exit");
	else if (status == 31)
		ft_putstr("Error\nIncorrect map: Two or more exits");
	else if (status == 4)
		ft_putstr("Error\nIncorrect map: No coins");
	else if (status == 5)
		ft_putstr("Error\nIncorrect map: Wrong characters");
	else
		return ;
}

void	get_counts(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->player_count = 0;
	map->exit_count = 0;
	map->coins_count = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == 'P')
				map->player_count++;
			if (map->grid[i][j] == 'E')
				map->exit_count++;
			if (map->grid[i][j] == 'C')
				map->coins_count++;
			j++;
		}
		i++;
	}
}

int	check_borders(char **grid, int height)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if ((grid[i][j] != '1') && ((i == 0) || (j == 0)
			|| (j == ft_strlen(grid[i]) - 1) || (i == height - 1)))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	get_map_status(t_map *map)
{
	if (map->player_count == 0)
		map->status = 20;
	else if (map->player_count > 1)
		map->status = 21;
	else if (map->exit_count == 0)
		map->status = 30;
	else if (map->exit_count > 1)
		map->status = 31;
	else if (map->coins_count == 0)
		map->status = 4;
	else if (check_borders(map->grid, map->height))
		map->status = 1;
	else
		map->status = 0;
	printf("Map status - %d\n", map->status);
}

int	check_map(t_map *map)
{
	get_counts(map);
	get_map_status(map);
	if (map->status)
		print_error(map->status);
	printf("Players - %d\nExits - %d\nCoins - %d\n", map->player_count, map->exit_count, map->coins_count);
	return (0);
}

// СДЕЛАТЬ ПРОВЕРКУ НА НЕПРАВИЛЬНЫЕ СИМВОЛЫ!