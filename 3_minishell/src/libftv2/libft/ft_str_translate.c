/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:34:56 by rusty             #+#    #+#             */
/*   Updated: 2022/02/26 17:17:10 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_len(char *line, char was, char will)
{
	size_t	len;

	len = 0;
	while (*line)
	{
		if (will)
		{
			++len;
			++line;
		}
		else if (!will)
		{
			if (*line != was)
				++len;
			++line;
		}
	}
	return (len + 1);
}

char	*ft_str_translate(char *line, char was, char will)
{
	char	*ret;
	size_t	len;
	size_t	i;

	i = 0;
	len = find_len(line, was, will);
	ret = ft_zalloc(len);
	while (i < len)
	{
		if (will)
		{
			if (*line == was)
				ret[i++] = will;
			else
				ret[i++] = *line;
			++line;
		}
		else if (!will)
		{
			if (*line != was)
				ret[i++] = *line;
			++line;
		}
	}
	return (ret);
}
