/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmp_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:39:08 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/22 14:39:28 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmp.h"

char	*ftmp_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	if (s1 == NULL)
		return (NULL);
	ret = ftmp_zalloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, s1, ft_strlen(s1));
	ft_strlcpy(ret + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (ret);
}
