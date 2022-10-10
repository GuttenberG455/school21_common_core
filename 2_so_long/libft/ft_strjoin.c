/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:19:15 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/08 11:50:16 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*str;

	if (!s1 && !s2)
		return (0);
	len_s1 = ft_strlen((char *) s1);
	len_s2 = ft_strlen((char *) s2);
	str = malloc(sizeof(char) * (len_s1 + len_s2) + 1);
	if (!str)
		return (0);
	ft_memmove(str, s1, len_s1);
	ft_memmove(str + len_s1, s2, len_s2);
	str[len_s1 + len_s2] = 0;
	free((char *) s1);
	return (str);
}
