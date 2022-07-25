/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:33:04 by david             #+#    #+#             */
/*   Updated: 2022/07/25 13:43:33 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	count_size(char *str, char ch)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
		if (str[i++] != ch)
			j++;
	return (j + 1);
}

char	*ft_remove_char(char *str, char ch)
{
	char	*res;
	int		i;
	int		j;

	res = ft_zalloc(sizeof(char) * count_size(str, ch));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ch)
			res[j++] = str[i];
		i++;
	}
	res[j] = '\0';
	return (res);
}
