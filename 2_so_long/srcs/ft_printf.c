/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:15:11 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/23 18:40:07 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_one(va_list ap, char specifier)
{
	if (specifier == 'd')
		return (ft_print_d(ap));
	else
		return (0);
}

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

int	ft_printf(const char *fstr, ...)
{
	int			count;
	char		spec;
	va_list		ap;

	count = 0;
	va_start(ap, fstr);
	while (*fstr)
	{
		if (*fstr == '%')
		{
			fstr++;
			spec = *fstr;
			count += ft_print_one(ap, spec);
			fstr++;
		}
		else
		{
			ft_putchar_fd(*fstr, 1);
			count++;
			fstr++;
		}
	}
	va_end(ap);
	return (count);
}
