/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_mll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:06:12 by rusty             #+#    #+#             */
/*   Updated: 2022/03/05 17:26:26 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	less_mll(const char *str)
{
	unsigned long long	ret;
	int					sig;

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
		if (ret > 9223372036854775807ULL && sig == 1)
			return (1);
		if (ret > 9223372036854775808ULL && sig == -1)
			return (1);
		++str;
	}
	return (0);
}
