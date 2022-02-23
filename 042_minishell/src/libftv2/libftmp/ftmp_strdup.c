/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmp_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:05:59 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/22 14:28:55 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmp.h"

char	*ftmp_strdup(const char *s1)
{
	char		*ret;
	size_t		len;

	len = ft_strlen(s1);
	ret = ftmp_zalloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, s1, len);
	ret[len] = '\0';
	return (ret);
}