/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:09:46 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/12/27 16:11:39 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd_p(char *s, int fd)
{
	int	strlen;

	if (s == NULL)
	{
		ft_putstr_fd_p("(null)", fd);
		return (6);
	}
	strlen = ft_strlen(s);
	while (*s)
	{
		ft_putchar_fd_p(*s, fd);
		++s;
	}
	return (strlen);
}
