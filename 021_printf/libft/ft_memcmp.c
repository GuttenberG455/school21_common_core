/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:25:23 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/07 11:45:26 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *memptr1, const void *memptr2, size_t size)
{
	size_t			i;
	int				diff;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	diff = 0;
	s1 = (unsigned char *) memptr1;
	s2 = (unsigned char *) memptr2;
	while (i < size)
	{
		if (s1[i] != s2[i])
		{
			diff = s1[i] - s2[i];
			return (diff);
		}
		i++;
	}
	return (diff);
}
