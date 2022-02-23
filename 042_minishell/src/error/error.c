/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:53:05 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/23 12:43:29 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "error.h"

int	err_return_one(char *module, char *text)
{
	ft_putstr_fd(module, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(text, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

void	*err_return_null(char *module, char *text)
{
	ft_putstr_fd(module, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(text, 2);
	ft_putstr_fd("\n", 2);
	return (NULL);
}

int	err_return_zero(char *module, char *text)
{
	ft_putstr_fd(module, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(text, 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

int	err_return_minus(char *module, char *text)
{
	ft_putstr_fd(module, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(text, 2);
	ft_putstr_fd("\n", 2);
	return (-1);
}