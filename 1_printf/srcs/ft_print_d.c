/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:24:06 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/21 12:53:04 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_neg_int_d(int num, int *count)
{
	if (num == (-2147483648))
	{
		ft_putstr_fd("-2", 1);
		*count += 2;
		num = num % 1000000000;
		num = -num;
	}
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		*count += 1;
		num = -num;
	}
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		*count += 1;
	}
	return (num);
}

int	ft_putnbr_d(int n)
{
	int	dec;
	int	count;

	count = 0;
	dec = 1000000000;
	n = ft_neg_int_d(n, &count);
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

int	ft_print_d(va_list ap)
{
	int	num;

	num = va_arg(ap, int);
	return (ft_putnbr_d(num));
}
