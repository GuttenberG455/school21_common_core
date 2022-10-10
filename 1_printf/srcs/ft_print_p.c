/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:16:30 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/21 11:23:02 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	hex_digit(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
		return ('a' + v - 10);
}

int	print_start_of_hex(uintptr_t ptr, int *iter)
{
	char	ch;

	ch = '0';
	while (ch == '0')
	{
		ch = hex_digit((ptr >> *iter) & 0xf);
		*iter -= 4;
	}
	ft_putchar_fd(ch, 1);
	return (3);
}

int	print_address_hex(void *p)
{
	int				i;
	int				count;
	uintptr_t		ptr ;

	if (!p)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	ptr = (uintptr_t) p;
	ft_putstr_fd("0x", 1);
	i = sizeof(void *) * 8 - 4;
	count = print_start_of_hex(ptr, &i);
	while (i >= 0)
	{
		ft_putchar_fd(hex_digit((ptr >> i) & 0xf), 1);
		count++;
		i -= 4;
	}
	return (count);
}

int	ft_print_p(va_list ap)
{
	void	*ptr;

	ptr = va_arg(ap, void *);
	return (print_address_hex(ptr));
}
