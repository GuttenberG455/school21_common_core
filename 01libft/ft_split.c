/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:06:07 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/09 11:59:52 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, char sep)
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

static char	*ft_malloc_word(char const *str, char sep)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && (str[i] != sep))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (word == 0)
		return (0);
	i = 0;
	while (str[i] && (str[i] != sep))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char sep)
{
	char	**arr;
	int		i;
	int		j;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	arr = (char **)malloc(sizeof(char *) * (ft_count_words(s, sep) + 1));
	if (arr == 0)
		return (0);
	while (s[i])
	{
		while (s[i] && (s[i] == sep))
			i++;
		if (s[i] && (s[i] != sep))
		{
			arr[j] = ft_malloc_word(&s[i], sep);
			j++;
			while (s[i] && (s[i] != sep))
				i++;
		}
	}
	arr[j] = 0;
	return (arr);
}
