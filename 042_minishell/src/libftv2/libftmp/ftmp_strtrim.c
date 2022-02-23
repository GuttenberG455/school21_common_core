/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmp_strtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:40:35 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/22 14:40:57 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmp.h"

static char	ftmp_found_set( char s1, char const *set)
{
	while (*set)
		if (s1 == *set++)
			return (1);
	return (0);
}

char	*ftmp_strtrim(char const *s1, char const *set)
{
	const char	*end;
	char		*ret;

	if (s1 == NULL)
		return (NULL);
	end = &s1[ft_strlen(s1) - 1];
	while (ftmp_found_set(*s1, set) && *s1)
		++s1;
	while (ftmp_found_set(*end, set) && end > s1)
		--end;
	ret = ftmp_substr(s1, 0, end - s1 + 1);
	if (ret == NULL)
		return (NULL);
	ret[end - s1 + 1] = '\0';
	return (ret);
}