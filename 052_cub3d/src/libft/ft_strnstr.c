/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamcha <tyamcha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:34:30 by tyamcha           #+#    #+#             */
/*   Updated: 2021/10/10 16:58:24 by tyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	hl;
	size_t	nl;
	size_t	i;

	hl = ft_strlen(h);
	nl = ft_strlen(n);
	if (hl != 0 && nl != 0 && len == 0)
		return (0);
	if (!hl && !nl)
		return ((char *)h);
	i = 0;
	while (*h)
	{
		if (i + ft_strlen(n) > len)
			return (NULL);
		if (!ft_strncmp(h, n, ft_strlen(n)))
			return ((char *)h);
		h++;
		i++;
	}
	return (NULL);
}
