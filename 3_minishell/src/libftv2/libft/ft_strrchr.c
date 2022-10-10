/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:22:26 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/10/10 20:40:30 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ret;

	if (c == '\0')
		return (ft_strchr(s, c));
	ret = (NULL);
	while (*s)
	{
		if (*((unsigned char *)s) == (unsigned char)c)
			ret = s;
		++s;
	}
	return ((char *)ret);
}
