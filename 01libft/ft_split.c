/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:06:07 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/07 14:31:43 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_count_words(char *str, char sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == sep))
			i++;
		if (str[i] && (str[i] != sep))
		{
			count++;
			while (str[i] && (str[i] != sep))
				i++;
		}
	}
	return (count);
}

static char	*ft_malloc_word(char *str, char sep)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && (str[i] != sep))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && (str[i] != sep))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char *str, char sep)
{
	char	**arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	arr = (char **)malloc(sizeof(char *) * (ft_count_words(str, sep) + 1));
	while (str[i])
	{
		while (str[i] && (str[i] == sep))
			i++;
		if (str[i] && (str[i] != sep))
		{
			arr[j] = ft_malloc_word(&str[i], sep);
			j++;
			while (str[i] && (str[i] != sep))
				i++;
		}
	}
	arr[j] = 0;
	return (arr);
}
