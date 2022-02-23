/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmp_strmapi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:34:04 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/22 14:35:00 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmp.h"

char	*ftmp_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*ret;
	unsigned int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	ret = ftmp_strdup(s);
	if (ret == NULL)
		return (NULL);
	while (ret[i])
	{
		ret[i] = (*f)(i, s[i]);
		++i;
	}
	return (ret);
}
