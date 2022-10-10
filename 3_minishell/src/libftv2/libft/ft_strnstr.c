/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:30:31 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/10/10 20:40:29 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!ft_strlen(haystack) && len <= 0)
		return ("");
	if (haystack[0] == '\0' && needle[0] == '\0' )
		return ("");
	while (*haystack)
	{
		if (len < ft_strlen(needle))
			return (NULL);
		if (!(ft_strncmp(haystack, needle, ft_strlen(needle))))
			return ((char *)haystack);
		++haystack;
		--len;
	}
	return (NULL);
}
