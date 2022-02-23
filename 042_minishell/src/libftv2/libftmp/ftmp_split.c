/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmp_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:55:04 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/22 14:42:54 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmp.h"

static int	tmp_count_words(const char *string, char c)
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

static void	tmp_free_split(char **buf, int count_wrd)
{
	int	i;

	i = 0;
	while (i++ <= count_wrd)
		if (buf[i])
			free(buf[i]);
	free(buf);
}

static int	tmp_check_word(char **buf, int i, int words)
{
	if (!buf[i])
	{
		tmp_free_split(buf, words);
		return (1);
	}
	return (0);
}

static void	tmp_found_word(char **buf, const char	**s, int i, char c)
{
	const char	*start_w;
	const char	*end_w;

	while (**s == c)
		++(*s);
	start_w = *s;
	while (**s != c && **s != '\0')
		++(*s);
	end_w = *s;
	buf[i] = ftmp_substr(start_w, 0, end_w - start_w);
}

char	**ftmp_split(char const *s, char c)
{
	int			words;
	int			i;
	char		**buf;
	const char	*s1;

	i = 0;
	s1 = s;
	if (s == NULL)
		return (NULL);
	words = tmp_count_words(s1, c);
	buf = ftmp_zalloc(sizeof(char *) * (words + 1));
	if (!buf)
		return (NULL);
	buf[words] = NULL;
	while (i < words)
	{
		tmp_found_word(buf, &s, i, c);
		if (tmp_check_word(buf, i, words))
			return (NULL);
		++i;
	}
	return (buf);
}
