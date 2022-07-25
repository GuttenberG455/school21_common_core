/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:37:29 by majacqua          #+#    #+#             */
/*   Updated: 2022/07/25 14:36:52 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	validate_input(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		err_exit("Wrong amount of arguments");
	if (!ft_strnstr(argv[1], ".cub", INT_MAX))
		err_exit("Wrong map extension (.cub expected)");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		err_exit("Wrong file");
	close(fd);
}
