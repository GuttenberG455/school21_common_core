/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:10:34 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/21 17:10:34 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int n)
{
	int	dec;
	int	count;

	count = 0;
	dec = 1000000000;
	while (dec > n)
		dec = dec / 10;
	while (dec >= 1)
	{
		if (dec > n)
		{
			ft_putchar_fd('0', 1);
			count++;
		}
		else
		{
			ft_putchar_fd(n / dec + '0', 1);
			count++;
		}
		n = n % dec;
		dec = dec / 10;
	}
	return (count);
}

int	ft_print_u(va_list ap)
{
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	return (ft_putnbr_u(num));
}
