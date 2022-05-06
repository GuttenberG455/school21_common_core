/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:17:35 by majacqua          #+#    #+#             */
/*   Updated: 2022/05/06 18:51:05 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int	exit_txt(char *text)
{
	ft_putstr_fd("Error! Cub3D: ", 2);
	ft_putstr_fd(text, 2);
	ft_putstr_fd("\n", 2);
	ft_free();
	exit(1);
}