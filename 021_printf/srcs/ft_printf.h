/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:52:54 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/21 16:31:34 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int	ft_printf(const char *fstr, ...);
int	ft_get_specifier(const char *fstr);
int	ft_print_one(va_list ap, char specifier);

int	ft_print_percent(va_list ap);
int	ft_print_c(va_list ap);
int	ft_print_d(va_list ap);
int	ft_print_i(va_list ap);
int	ft_print_p(va_list ap);
int	ft_print_s(va_list ap);
int	ft_print_u(va_list ap);
int	ft_print_x(va_list ap);
int	ft_print_bigx(va_list ap);

#endif