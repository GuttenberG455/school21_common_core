/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:08:24 by ubeetroo          #+#    #+#             */
/*   Updated: 2022/02/18 01:08:59 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	void	count_len(long long n, int *size)
{
	if (n < 0)
		n *= -1;
	if (n >= 10)
	{
		count_len(n / 10, size);
		*size += 1;
	}
	else
		*size += 1;
}

static	void	fill(long n, int *i, char *ret)
{
	if (n < 0)
	{
		ret[0] = '-';
		*i = 1;
		n *= -1;
	}
	if (n >= 10)
	{
		fill(n / 10, i, ret);
		fill(n % 10, i, ret);
	}
	else
		ret[(*i)++] = '0' + n;
}

char	*ft_itoa(int n)
{
	int		size;
	char	*ret;
	long	nn;
	int		i;

	i = 0;
	nn = n;
	size = 0;
	count_len(nn, &size);
	if (nn >= 0)
	{
		ret = ft_zalloc(sizeof(char) * (size + 1));
		if (ret)
			ret[size] = '\0';
	}
	else
	{
		ret = ft_zalloc(sizeof(char) * (size + 2));
		if (ret)
			ret[size + 1] = '\0';
	}
	if (ret == NULL)
		return (NULL);
	fill(nn, &i, ret);
	return (ret);
}
