/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:37:17 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/10/10 20:40:27 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	len_dst;
	size_t	len_src;

	len_dst = 0;
	while (len_dst < dstsize && ft_isprint(dst[len_dst]))
		++len_dst;
	len_src = ft_strlen(src);
	if (dstsize == 0)
		return (len_dst + len_src);
	ft_strlcpy((dst + len_dst), src, dstsize - len_dst);
	return (len_dst + len_src);
}
