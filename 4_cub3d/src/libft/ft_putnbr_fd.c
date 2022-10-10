/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:34:30 by tyamcha           #+#    #+#             */
/*   Updated: 2021/10/13 13:27:57 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned int	ft_abs(int n)
{
	if (n < 0)
		return ((unsigned int) -n);
	return ((unsigned int)n);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	abs_n;

	if (n < 0)
		ft_putchar_fd('-', fd);
	abs_n = ft_abs(n);
	if (abs_n >= 10)
		ft_putnbr_fd(abs_n / 10, fd);
	ft_putchar_fd((char)(abs_n % 10 + 48), fd);
}
