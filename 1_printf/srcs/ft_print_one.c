/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:55:06 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/21 16:49:39 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_one(va_list ap, char specifier)
{
	if (specifier == '%')
		return (ft_print_percent(ap));
	else if (specifier == 'c')
		return (ft_print_c(ap));
	else if (specifier == 's')
		return (ft_print_s(ap));
	else if (specifier == 'p')
		return (ft_print_p(ap));
	else if (specifier == 'd')
		return (ft_print_d(ap));
	else if (specifier == 'i')
		return (ft_print_d(ap));
	else if (specifier == 'u')
		return (ft_print_u(ap));
	else if (specifier == 'x')
		return (ft_print_x(ap));
	else if (specifier == 'X')
		return (ft_print_bigx(ap));
	else
		return (0);
}
