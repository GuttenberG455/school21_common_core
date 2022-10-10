/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:34:30 by tyamcha           #+#    #+#             */
/*   Updated: 2021/10/13 18:32:16 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	res;
	int		neg;

	neg = 1;
	if (!(*str))
		return (0);
	while (ft_strchr("\n \t\r\v\f", *str))
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '+' || *str == '-')
		str++;
	res = 0;
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str++ - 48);
		if (res * neg > 2147483647)
			return (-1);
		if (res * neg < -2147483648)
			return (0);
	}
	return ((int)(neg * res));
}
