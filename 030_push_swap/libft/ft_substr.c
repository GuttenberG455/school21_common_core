/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:52:26 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/12 10:07:29 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_statgetlen(char const *s, unsigned int start, size_t size)
{
	size_t	len;

	if ((ft_strlen(s) - start) < size)
		len = (ft_strlen(s) - start);
	else
		len = size;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char));
		str[0] = 0;
		return (str);
	}
	len = ft_statgetlen(s, start, size);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	i = (size_t) start;
	j = 0;
	while (j < len)
		str[j++] = s[i++];
	str[j] = 0;
	return (str);
}
