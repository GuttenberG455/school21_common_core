/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:14:10 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/07 16:05:10 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_statstrdup(char *src)
{
	char	*ptr;
	int		i;

	i = 0;
	while (src[i])
		i++;
	ptr = malloc(i);
	i = 0;
	if (ptr == 0)
		return (0);
	while (src[i] != '\0')
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

static int	itoa_isnegative(int *n)
{
	if (*n < 0)
	{
		*n *= -1;
		return (1);
	}
	return (0);
}

static int	ft_getintlen(int n)
{
	int	len;

	len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		negative;
	char	*str;

	if (n == -2147483648)
		return (ft_statstrdup("-2147483648"));
	if (n == 0)
		return (ft_statstrdup("0"));
	negative = itoa_isnegative(&n);
	len = ft_getintlen(n);
	len += negative;
	str = (char *)malloc(sizeof(char) * len);
	if (str == 0)
		return (0);
	str[--len] = 0;
	while (len)
	{
		len--;
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
