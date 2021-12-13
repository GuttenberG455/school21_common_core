/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:33:56 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/13 12:21:26 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_map.h"
#include "../../includes/get_grid.h"

void	print_error(int status)
{
	if (status == 10)
		ft_putstr("Error\nIncorrect map: No borders");
	else if (status == 11)
		ft_putstr("Error\nIncorrect map: Wrong dimensions");
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
	printf("Sum of all characters - [%d]\n", amount);
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
	else if (check_dimensions(map))
		map->status = 11;
	else if (check_characters(map))
		map->status = 5;
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
	printf("Players - %d Exits - %d Coins - %d\n", map->player_count, map->exit_count, map->coins_count);
	printf("Height - %d\t Width - %d\n", map->height, map->width);
	return (0);
}
