/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmp_gnl_ut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:53:35 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/22 14:54:48 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmp.h"

void	*ftmp_memcpy_gnlb(void *dst, const void *src, size_t n)
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

char	*ftmp_strjoin_gnlb(char *s1, char *s2)
{
	char	*ret;
	size_t	len;

	if (s1 == NULL)
		len = 0;
	else
		len = ftmp_strlen_gnlb(s1);
	ret = ftmp_zalloc((len + ftmp_strlen_gnlb(s2) + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ftmp_memcpy_gnlb(ret, s1, len);
	ftmp_strlcpy_gnlb(ret + len, s2, ftmp_strlen_gnlb(s2) + 1);
	return (ret);
}

char	*ftmp_strchr_gnlb(const char *s, int c)
{
	size_t	ln;

	if (!s)
		return (NULL);
	ln = ftmp_strlen_gnlb(s) + 1;
	while (ln)
	{
		if (*s == c)
			return ((char *)s);
		++s;
		--ln;
	}
	return (NULL);
}

size_t	ftmp_strlen_gnlb(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		++s;
		++len;
	}
	return (len);
}

size_t	ftmp_strlcpy_gnlb(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;

	len_src = ftmp_strlen_gnlb(src);
	if (len_src == 0 || dstsize == 0)
	{
		if (dstsize != 0)
			*dst = '\0';
		return (len_src);
	}
	if (dstsize > len_src + 1)
		ftmp_memcpy_gnlb(dst, src, len_src + 1);
	else
	{
		ftmp_memcpy_gnlb(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (len_src);
}
