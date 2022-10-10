/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:29:06 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/10/11 14:05:56 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_found_set( char s1, char const *set)
{
	while (*set)
		if (s1 == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*end;
	char		*ret;

	if (s1 == NULL)
		return (NULL);
	end = &s1[ft_strlen(s1) - 1];
	while (ft_found_set(*s1, set) && *s1)
		++s1;
	while (ft_found_set(*end, set) && end > s1)
		--end;
	ret = ft_substr(s1, 0, end - s1 + 1);
	if (ret == NULL)
		return (NULL);
	ret[end - s1 + 1] = '\0';
	return (ret);
}
