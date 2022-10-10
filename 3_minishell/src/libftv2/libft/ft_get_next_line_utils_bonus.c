/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:49:12 by ubeetroo          #+#    #+#             */
/*   Updated: 2022/02/18 01:04:54 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy_gnlb(void *dst, const void *src, size_t n)
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

char	*ft_strjoin_gnlb(char *s1, char *s2)
{
	char	*ret;
	size_t	len;

	if (s1 == NULL)
		len = 0;
	else
		len = ft_strlen_gnlb(s1);
	ret = ft_zalloc((len + ft_strlen_gnlb(s2) + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_memcpy_gnlb(ret, s1, len);
	ft_strlcpy_gnlb(ret + len, s2, ft_strlen_gnlb(s2) + 1);
	return (ret);
}

char	*ft_strchr_gnlb(const char *s, int c)
{
	size_t	ln;

	if (!s)
		return (NULL);
	ln = ft_strlen_gnlb(s) + 1;
	while (ln)
	{
		if (*s == c)
			return ((char *)s);
		++s;
		--ln;
	}
	return (NULL);
}

size_t	ft_strlen_gnlb(const char *s)
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

size_t	ft_strlcpy_gnlb(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;

	len_src = ft_strlen_gnlb(src);
	if (len_src == 0 || dstsize == 0)
	{
		if (dstsize != 0)
			*dst = '\0';
		return (len_src);
	}
	if (dstsize > len_src + 1)
		ft_memcpy_gnlb(dst, src, len_src + 1);
	else
	{
		ft_memcpy_gnlb(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (len_src);
}
