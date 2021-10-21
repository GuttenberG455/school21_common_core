/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:15:11 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/21 16:33:41 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_specifier(const char *fstr)
{
	fstr++;
	if (fstr)
	{
		return ((char) *fstr);
	}
	return (1);
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
			spec = ft_get_specifier(fstr);
			count += ft_print_one(ap, spec);
			fstr++;
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
