/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:02:54 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/21 11:32:25 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(va_list ap)
{
	ft_putchar_fd('%', 1);
	return (1);
}

int	ft_print_c(va_list ap)
{
	char	ch;

	ch = (char) va_arg(ap, int);
	ft_putchar_fd(ch, 1);
	return (1);
}
