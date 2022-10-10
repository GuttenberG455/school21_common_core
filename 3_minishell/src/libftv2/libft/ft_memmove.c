/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:19:17 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/10/13 15:49:57 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == NULL && src == NULL && len)
		return (NULL);
	if (dst < src)
		dst = ft_memcpy(dst, src, len);
	else
	{
		while (len-- > 0)
			*((char *)dst + len) = *((const char *)src + len);
	}
	return (dst);
}
