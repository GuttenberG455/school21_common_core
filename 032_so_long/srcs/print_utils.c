/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:42:39 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/21 16:42:43 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/map.h"
#include "../includes/game.h"

void	printf_map_grid(t_prog *prog)
{
	int	i;

	i = 0;
	if (!prog->map.grid)
		return ;
	printf("Players - %d Exits - %d Coins - %d\n",
		prog->map.player_count, prog->map.exit_count, prog->map.coins_count);
	while (prog->map.grid[i])
	{
		printf("%s\n", prog->map.grid[i]);
		i++;
	}
}
