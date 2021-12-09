/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:45:21 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/09 11:45:07 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	diff = 0;
	while (((s1[i] != 0) || (s2[i] != 0)) && i < n)
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
		{
			diff = (unsigned char) s1[i] - (unsigned char) s2[i];
			return (diff);
		}
		i++;
	}
	return (diff);
}
