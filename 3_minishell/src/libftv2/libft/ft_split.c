/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:33:15 by ubeetroo          #+#    #+#             */
/*   Updated: 2022/02/18 01:05:22 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *string, char c)
{
	int	count;

	count = 0;
	while (*string)
	{
		while (*string == c)
			++string;
		if (*string)
		{
			++count;
			while (*string != c && *string)
				++string;
		}
	}
	return (count);
}

static void	free_split(char **buf, int count_wrd)
{
	int	i;

	i = 0;
	while (i++ <= count_wrd)
		if (buf[i])
			free(buf[i]);
	free(buf);
}

static int	check_word(char **buf, int i, int words)
{
	if (!buf[i])
	{
		free_split(buf, words);
		return (1);
	}
	return (0);
}

static void	found_word(char **buf, const char	**s, int i, char c)
{
	const char	*start_w;
	const char	*end_w;

	while (**s == c)
		++(*s);
	start_w = *s;
	while (**s != c && **s != '\0')
		++(*s);
	end_w = *s;
	buf[i] = ft_substr(start_w, 0, end_w - start_w);
}

char	**ft_split(char const *s, char c)
{
	int			words;
	int			i;
	char		**buf;
	const char	*s1;

	i = 0;
	s1 = s;
	if (s == NULL)
		return (NULL);
	words = count_words(s1, c);
	buf = ft_zalloc(sizeof(char *) * (words + 1));
	if (!buf)
		return (NULL);
	buf[words] = NULL;
	while (i < words)
	{
		found_word(buf, &s, i, c);
		if (check_word(buf, i, words))
			return (NULL);
		++i;
	}
	return (buf);
}
