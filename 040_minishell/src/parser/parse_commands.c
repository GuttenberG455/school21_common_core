/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:53:49 by rusty             #+#    #+#             */
/*   Updated: 2022/03/04 05:32:24 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*unite_split(char **split)
{
	int		i;
	int		len;
	char	*str;

	i = 1;
	len = ft_split_len(split);
	if (len == 1)
		return (ft_strdup(split[0]));
	else if (len > 1)
	{
		str = ft_strdup(split[0]);
		while (i < len)
			str = ft_strjoin(str, split[i++]);
		return (str);
	}
	return (ft_strdup(""));
}

char	*clean_quotes(char *input)
{
	char	**split;
	char	quote;
	int		i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '\"')
		{
			quote = input[i];
			input[i++] = '\6';
			while (input[i] && input[i] != quote)
			{
				input[i] = input[i] * !(input[i] == ' ') + \
				'\r' * (input[i] == ' ');
				++i;
			}
			if (input[i])
				input[i] = '\6';
		}
		if (input[i])
			++i;
	}
	split = ft_split(input, '\6');
	return (unite_split(split));
}

int	parse_commands(t_cmd *cmd)
{
	int		i;
	char	*tmp;
	char	quote;

	i = 0;
	tmp = clean_quotes(cmd->input);
	while (tmp[i])
	{
		if (tmp[i] == '\'' || tmp[i] == '\"')
		{
			quote = tmp[i++];
			while (tmp[i] && tmp[i] != quote)
				++i;
		}
		tmp[i] = tmp[i] * !(tmp[i] == ' ') + '\6' * (tmp[i] == ' ');
		if (tmp[i])
			++i;
	}
	tmp = ft_str_translate(tmp, '\r', ' ');
	cmd->args = ft_split(tmp, '\6');
	cmd->cmd_name = cmd->args[0];
	return (0);
}
