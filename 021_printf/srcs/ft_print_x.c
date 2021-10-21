/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:53:45 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/21 12:12:05 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int nbr, const char *base)
{
	char		arr[15];
	int			j;
	int			count;

	j = 0;
	count = 0;
	if (nbr < 0)
	{
		nbr = 4294967295 + nbr;
	}
	while (nbr >= 16)
	{
		arr[j] = nbr % 16;
		nbr = nbr / 16;
		j++;
	}
	arr[j] = nbr;
	while (j >= 0)
	{
		ft_putchar_fd(base[(int)arr[j]], 1);
		count++;
		j--;
	}
	return (count);
}

int	ft_print_bigx(va_list ap)
{
	int			num;
	const char	base[17] = "0123456789ABCDEF";

	num = va_arg(ap, int);
	return (ft_putnbr_hex(num, base));
}

int	ft_print_x(va_list ap)
{
	int			num;
	const char	base[17] = "0123456789abcdef";

	num = va_arg(ap, int);
	return (ft_putnbr_hex(num, base));
}
