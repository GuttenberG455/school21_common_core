/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:41:20 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/23 18:25:10 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include <unistd.h>

void	check_args(int argc, char **argv)
{
	if (argc < 2)
		ft_close("Error\nNo map argument\n");
	else if (argc > 2)
		ft_close("Error\nWrong amount of arguments\n");
	else if (!ft_strnstr(argv[1], ".ber", INT_MAX))
		ft_close("Error\nWrong map extension (.ber expected)\n");
}

int	main(int argc, char **argv)
{
	t_prog	prog;

	check_args(argc, argv);
	get_dimensions(&prog, argv);
	get_map_grid(&prog, argv[1]);
	check_map_grid(&prog);
	prog.mlx = mlx_init();
	prog.window = ft_new_window(prog.mlx, prog.map);
	draw_map(prog);
	mlx_key_hook(prog.window.ptr, *ft_input, &prog);
	mlx_loop(prog.mlx);
	return (0);
}
