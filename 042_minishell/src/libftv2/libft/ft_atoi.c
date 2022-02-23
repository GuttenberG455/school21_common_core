/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:35:28 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/10/15 12:50:11 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	ret;
	int			sig;

	ret = 0;
	sig = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'\
	|| *str == '\f' || *str == '\r')
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sig *= -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		ret = 10 * ret + *str - 48;
		if (ret > 2147483647 && sig == 1)
			return (-1);
		if (ret > 2147483648 && sig == -1)
			return (0);
		++str;
	}
	return (sig * ret);
}
