/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 04:53:43 by rusty             #+#    #+#             */
/*   Updated: 2022/03/04 05:42:23 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	skip_quotes_str(char **str, char **res)
{
	char	*s_ret;
	char	*r_ret;

	s_ret = *str;
	r_ret = *res;
	*(r_ret++) = *(s_ret++);
	while (*s_ret && *s_ret != '\'')
		*(r_ret++) = *(s_ret++);
	*res = r_ret;
	*str = s_ret;
}

void	skip_sing_quote(char *str, int *i)
{
	++(*i);
	while (str[*i] && str[*i] != '\'')
		++(*i);
}

void	skip_quotes_int(char *str, int *i)
{
	char	quote;

	quote = str[(*i)++];
	while (str[*i] && str[*i] != quote)
		++(*i);
}
