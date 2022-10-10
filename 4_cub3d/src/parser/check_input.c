/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:37:29 by majacqua          #+#    #+#             */
/*   Updated: 2022/05/06 18:50:37 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void check_input(int argc, char **argv)
{
	if (argc != 2)
		exit_txt("Wrong amount of arguments");
	if (!ft_strnstr(argv[1], ".cub", INT_MAX))
		exit_txt("Wrong map extension (.cub expected)");
}