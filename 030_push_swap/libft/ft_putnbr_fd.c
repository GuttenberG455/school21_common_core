/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:34:53 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/09 11:44:21 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

static int	ft_neg_int(int num, int fd)
{
	if (num == (-2147483648))
	{
		ft_putchar('-', fd);
		ft_putchar('2', fd);
		num = num % 1000000000;
		num = -num;
	}
	if (num < 0)
	{
		ft_putchar('-', fd);
		num = -num;
	}
	if (num == 0)
		ft_putchar('0', fd);
	return (num);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	dec;

	dec = 1000000000;
	n = ft_neg_int(n, fd);
	while (dec > n)
		dec = dec / 10;
	while (dec >= 1)
	{
		if (dec > n)
			ft_putchar('0', fd);
		else
			ft_putchar(n / dec + '0', fd);
		n = n % dec;
		dec = dec / 10;
	}
}
