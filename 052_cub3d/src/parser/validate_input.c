/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:37:29 by majacqua          #+#    #+#             */
/*   Updated: 2022/06/15 13:16:31 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void validate_input(int argc, char **argv)
{
	int fd;

	if (argc != 2)
		err_exit("Wrong amount of arguments");
	if (!ft_strnstr(argv[1], ".cub", INT_MAX))
		err_exit("Wrong map extension (.cub expected)");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		err_exit("Wrong file");	
	close(fd);
}