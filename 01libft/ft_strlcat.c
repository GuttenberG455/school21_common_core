/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:55:26 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/09 11:44:48 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getstrlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	k;
	size_t	dest_size;
	size_t	src_size;

	i = 0;
	dest_size = ft_getstrlen(dest);
	src_size = ft_getstrlen(src);
	k = dest_size;
	if (dest_size < size - 1 && size > 0)
	{
		while (src[i] && dest_size + i < size - 1)
		{
			dest[k] = src[i];
			k++;
			i++;
		}
		dest[k] = 0;
	}
	if (dest_size >= size)
		dest_size = size;
	return (dest_size + src_size);
}
