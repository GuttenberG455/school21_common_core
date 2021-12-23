/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:33:56 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/23 18:23:02 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/game.h"

int	count_ch_in_grid(char **grid, int ch)
{
	int	i;
	int	j;
	int	count;

	if (!grid)
		return (0);
	i = 0;
	count = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == (char) ch)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	get_counts(t_map *map)
{
	map->player_count = count_ch_in_grid(map->grid, 'P');
	map->exit_count = count_ch_in_grid(map->grid, 'E');
	map->coins_count = count_ch_in_grid(map->grid, 'C');
}

int	check_borders(char **grid, int height, int width)
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
			|| (j == width - 1) || (i == height - 1)))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_characters(t_map *map)
{
	int	amount;

	amount = count_ch_in_grid(map->grid, 'P');
	amount += count_ch_in_grid(map->grid, 'E');
	amount += count_ch_in_grid(map->grid, 'C');
	amount += count_ch_in_grid(map->grid, '1');
	amount += count_ch_in_grid(map->grid, '0');
	amount += count_ch_in_grid(map->grid, 'Q');
	if (amount != map->width * map->height)
		return (1);
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
	else if (check_borders(map->grid, map->height, map->width))
		map->status = 10;
	else if (check_characters(map))
		map->status = 5;
	else
		map->status = 0;
}
