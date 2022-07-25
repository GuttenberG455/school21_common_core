/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:34:30 by tyamcha           #+#    #+#             */
/*   Updated: 2022/07/25 13:43:33 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	long int	ft_abs(long int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static	int	ft_disch(long int n)
{
	int			grade;
	long int	ten;

	grade = 0;
	ten = 1;
	if (n == 0)
		return (1);
	while (ten <= ft_abs(n))
	{
		grade++;
		ten *= 10;
	}
	return (grade);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			dis;
	long int	ln;

	ln = (long int)n;
	dis = ft_disch(ln);
	if (ln < 0)
		res = ft_zalloc(dis + 2);
	else
		res = ft_zalloc(dis + 1);
	if (!res)
		return (NULL);
	if (ln < 0 && dis++ != -1)
		res[0] = '-';
	ln = ft_abs(ln);
	res[dis--] = '\0';
	if (ln == 0)
		res[0] = '0';
	while (ln > 0)
	{
		res[dis--] = ln % 10 + '0';
		ln /= 10;
	}
	return (res);
}
