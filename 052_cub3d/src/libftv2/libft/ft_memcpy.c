/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:16:50 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/10/10 20:40:20 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL && src == NULL && n)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*((unsigned char *) dst) = *((unsigned const char *)src);
		++i;
		++dst;
		++src;
	}
	return (dst - i);
}
