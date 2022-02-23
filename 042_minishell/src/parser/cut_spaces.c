/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_spaces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:22:00 by rusty             #+#    #+#             */
/*   Updated: 2022/02/22 16:13:46 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*clean_spaces(char *input)
{
	int		i;
	int		j;
	char	*clean;
	char	quote;

	j = 0;
	i = 0;
	// printf("%s\n%ld\n", input, ft_strlen(input) + 1);
	clean = ft_zalloc(ft_strlen(input) + 2);
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '\"')
		{
			quote = input[i];
			clean[j++] = input[i++];
			while (input[i] && input[i] != quote)
				clean[j++] = input[i++];
		}
		if (!ft_strchr(" \t", input[i]))
			clean[j++] = input[i];
		else if (i != 0 && !ft_strchr(" \t", input[i - 1]))
			clean[j++] = ' ';
		if (input[i])
			++i;
	}
	return (clean);
}

char	*cut_spaces(char *input)
{
	char	*ret;

	// ret = ft_zalloc(ft_strlen(input) + 1);
	// input = ft_strtrim(input, " \t");
	// printf("%s\n%ld\n", input, ft_strlen(input) + 1);
	ret = clean_spaces(input);
	return (ret);
}
