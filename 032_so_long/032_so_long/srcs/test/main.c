/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:13:31 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/13 19:42:22 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

int	main(void)
{
	t_program	program;
	program.mlx = mlx_init();
	program.window = ft_new_window(program.mlx, 800, 600, "Dankest Dungeon");
}