/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:20:57 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/12/27 16:11:52 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd_p(long long n, int fd, int *len)
{
	if (n < 0)
	{
		ft_putchar_fd_p('-', fd);
		n = n * (-1);
		*len += 1;
	}
	if (n >= 10)
		ft_putnbr_fd_p(n / 10, fd, len);
	ft_putchar_fd_p('0' + (n % 10), fd);
	*len += 1;
}
