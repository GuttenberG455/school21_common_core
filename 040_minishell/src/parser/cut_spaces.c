/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_spaces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:22:00 by rusty             #+#    #+#             */
/*   Updated: 2022/03/04 05:44:38 by rusty            ###   ########.fr       */
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

	ret = clean_spaces(input);
	return (ret);
}
