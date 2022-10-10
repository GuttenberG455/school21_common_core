/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:00:09 by majacqua          #+#    #+#             */
/*   Updated: 2022/07/25 14:00:30 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c % 256)
			return ((char *)s);
		s++;
	}
	if (*s == c % 256)
		return ((char *)s);
	return (NULL);
}

size_t	gnl_strlen(const char *s)
{
	int	res;

	res = 0;
	if (!s)
		return (0);
	while (*s++)
		res++;
	return (res);
}

void	*gnl_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dest);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	res_len;

	if (!s1 && !s2)
		return (NULL);
	res_len = gnl_strlen(s1) + gnl_strlen(s2) + 1;
	res = (char *)ft_zalloc(res_len);
	if (!res)
		return (NULL);
	gnl_memmove(res, s1, gnl_strlen(s1));
	gnl_memmove(res + gnl_strlen(s1), s2, gnl_strlen(s2));
	res[res_len - 1] = '\0';
	return (res);
}
