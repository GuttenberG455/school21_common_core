/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:01:07 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/12/27 16:10:33 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_parse_option(const char **s, va_list *args)
{
	int	len;

	len = 0;
	if (!(**s))
		return (0);
	if (*((*s)++) == 'c')
		return (ft_putchar_fd_p(va_arg(*args, int), 1));
	else if (*((*s) - 1) == 's')
		return (ft_putstr_fd_p(va_arg(*args, char *), 1));
	else if (*((*s) - 1) == 'p')
		return (ft_putnbr_basep_p(va_arg(*args, unsigned long), *((*s) - 1)));
	else if (*((*s) - 1) == 'd' || *((*s) - 1) == 'i' || *((*s) - 1) == 'u')
	{
		if (*((*s) - 1) == 'u')
			ft_putnbr_fd_p(va_arg(*args, unsigned int), 1, &len);
		else
			ft_putnbr_fd_p(va_arg(*args, int), 1, &len);
		return (len);
	}
	else if (*((*s) - 1) == 'x' || *((*s) - 1) == 'X')
		return (ft_putnbr_base_p(va_arg(*args, long long), *((*s) - 1)));
	else if (*((*s) - 1) == '%')
		return (ft_putchar_fd_p('%', 1));
	else
		return (0);
}

static int	ft_workline(const char *s, va_list *args)
{
	int	total_len;

	total_len = 0;
	while (*s)
	{
		if (*s != '%')
			total_len += ft_putchar_fd_p(*(s++), 1);
		else
		{
			++s;
			total_len += ft_parse_option(&s, args);
		}
	}
	return (total_len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		ret;

	va_start(args, s);
	ret = ft_workline(s, &args);
	va_end(args);
	return (ret);
}
/*
#include <limits.h>
#include <stdio.h>
int	main(void)
{
	int i = ft_printf("cspdifuxX%");
	printf("\n^mine\n  not mine\n");
	int d = printf("cspdifuxX%");
	printf("\n");
	printf("%d %d", i, d);
}
*/