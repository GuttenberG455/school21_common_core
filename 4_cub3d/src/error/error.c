/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtwitch <rtwitch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:17:35 by majacqua          #+#    #+#             */
/*   Updated: 2022/07/25 14:33:48 by rtwitch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int	err_exit(char *text)
{
	ft_putstr_fd("Error! Cub3D: ", 2);
	ft_putstr_fd(text, 2);
	ft_putstr_fd("\n", 2);
	ft_free();
	exit(1);
}