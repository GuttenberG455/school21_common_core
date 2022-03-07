/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 07:47:13 by rusty             #+#    #+#             */
/*   Updated: 2022/03/04 04:35:52 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*replace_pipes(char *input)
{
	int		i;
	char	quote;

	i = -1;
	while (input[++i])
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			quote = input[i++];
			while (input[i] && input[i] != quote)
				++i;
			if (!input[i])
				return (NULL);
		}
		if (input[i] == '|')
			input[i] = '\6';
	}
	return (input);
}

char	*check_pipe(char *str)
{
	int		i;
	int		pipe_repeat;

	pipe_repeat = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			++i;
		if (str[i] == '\6' && pipe_repeat)
			return (NULL);
		else if (str[i] == '\6')
			pipe_repeat = 1;
		else
			pipe_repeat = 0;
		if (str[i])
			++i;
	}
	while (i > 0 && str[i] == ' ')
			--i;
	if (str[i] == '\6')
		return (NULL);
	else
		return (str);
}

char	**parse_pipes(char *input)
{
	char	**ret;

	input = replace_pipes(input);
	if (!input)
		return (err_return_null(M_SH, "according to subject unclosed quotes are not\
 accepted"));
	ret = ft_split(check_pipe(input), '\6');
	if (!ret)
		return (err_return_null(M_SH, " syntax error near unexpected\
token `|'"));
	return (ret);
}
