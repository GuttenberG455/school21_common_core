/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:55:26 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/12 10:06:59 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	k;
	size_t	dest_size;
	size_t	src_size;

	i = 0;
	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
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
