/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_global.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 07:57:51 by rusty             #+#    #+#             */
/*   Updated: 2022/03/04 05:34:43 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_flaq(char ch, int *flaq)
{
	if (*flaq == 0 && ch == '\"')
		*flaq = 1;
	else if (*flaq == 1 && ch == '\"')
		*flaq = 0;
}

char	*get_name(char *cmd)
{
	char	*tmp;

	if (*cmd != '$')
		return (NULL);
	++cmd;
	if (*cmd == '?' || ft_isdigit(*cmd))
		return (ft_substr(cmd, 0, 1));
	cmd = ft_strdup(cmd);
	tmp = cmd;
	if (ft_isalnum(*tmp) || *tmp == '_')
	{
		while (ft_isalnum(*tmp) || *tmp == '_')
			tmp++;
		return (ft_substr(cmd, 0, tmp - cmd));
	}
	return (NULL);
}

int	find_len(t_env *env, char *str, t_list	**vals)
{
	int		i;
	int		add_len;
	int		flaq;
	char	*name;

	i = 0;
	add_len = 0;
	flaq = 0;
	while (str[i])
	{
		check_flaq(str[i], &flaq);
		if (str[i] == '\'' && flaq == 0)
			skip_sing_quote(str, &i);
		name = get_name(&str[i]);
		if (name)
		{
			add_len += ft_strlen(get_env(env, name)) - 1;
			str += ft_strlen(name);
			ft_lstadd_back(vals, ft_lstnew(get_env(env, name)));
		}
		else if (str[i])
			++i;
	}
	return (i + add_len + 1);
}

void	move_res_str(char **res, char **str, char *name, char *val)
{
	*res += ft_strlen(val);
	*str += ft_strlen(name) + 1;
}

char	*put_global(t_env *env, char *str)
{
	char	*ret;
	char	*res;
	int		flaq;
	t_list	**vals;

	vals = ft_zalloc(sizeof(t_list *));
	res = ft_zalloc(find_len(env, str, vals));
	ret = res;
	flaq = 0;
	while (*str)
	{
		check_flaq(*str, &flaq);
		if (*str == '\'' && flaq == 0)
			skip_quotes_str(&str, &res);
		if (get_name(str))
		{
			ft_strlcpy(res, (*vals)->data, ft_strlen((*vals)->data) + 1);
			move_res_str(&res, &str, get_name(str), (*vals)->data);
			*vals = (*vals)->next;
		}
		else if (*str)
			*(res++) = *(str++);
	}
	return (ret);
}
