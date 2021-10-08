/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:52:26 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/07 19:49:49 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	if (start > ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char *));
		str[0] = 0;
		return (str);
	}
	if ((ft_strlen(s) - start) < size)
		len = (ft_strlen(s) - start);
	else
		len = size;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	i = (size_t) start;
	j = 0;
	while (j < len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
