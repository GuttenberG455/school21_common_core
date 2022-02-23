/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmp_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:36:59 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/23 14:36:36 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmp.h"

static size_t	ftmp_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

char	*ftmp_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	sze;

	if (s == NULL)
		return (NULL);
	if ((size_t) start >= ft_strlen(s))
		return (ftmp_zalloc(sizeof(char)));
	sze = (size_t)ftmp_min(ft_strlen(s + start), len);
	ret = ftmp_zalloc((sze + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s + start, sze + 1);
	return (ret);
}
