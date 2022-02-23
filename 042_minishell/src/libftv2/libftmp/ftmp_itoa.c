/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmp_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:34:43 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/22 14:35:31 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmp.h"

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
		ret = ftmp_zalloc(sizeof(char) * (size + 1));
		if (ret)
			ret[size] = '\0';
	}
	else
	{
		ret = ftmp_zalloc(sizeof(char) * (size + 2));
		if (ret)
			ret[size + 1] = '\0';
	}
	if (ret == NULL)
		return (NULL);
	fill(nn, &i, ret);
	return (ret);
}
