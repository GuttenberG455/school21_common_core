/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:25:51 by majacqua          #+#    #+#             */
/*   Updated: 2021/11/17 12:07:59 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.h"

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
