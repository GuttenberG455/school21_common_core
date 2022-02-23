/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_global.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 07:57:51 by rusty             #+#    #+#             */
/*   Updated: 2022/02/23 12:37:31 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
	char	*name;

	i = 0;
	add_len = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			++i;
			while (str[i] && str[i] != '\'')
				++i;
		}
		name = get_name(&str[i]);
		if (name)
		{
			add_len += ft_strlen(get_env_par(env, name)) - 1;
			str += ft_strlen(name);
			ft_lstadd_back(vals, ft_lstnew(get_env_par(env, name)));
		}
		else if (str[i])
			++i;
	}
	return (i + add_len + 1);
}

void	move_res_str(char **res, char **str, char *name, char *val)
{
	// printf("res %s + %ld\n", *res, ft_strlen(val));
	// printf("str %s + %ld\n", *str, ft_strlen(name) + 1);
	*res += ft_strlen(val);
	*str += ft_strlen(name) + 1;
	// printf("str %s + %ld\n", *str, ft_strlen(name) + 1);

}

char	*put_global(t_env *env, char *str)
{
	char	*ret;
	char	*res;
	t_list	**vals;

	vals = ft_zalloc(sizeof(t_list *));
	res = ft_zalloc(find_len(env, str, vals));
	// printf("put global\n len is %d\n", find_len(env, str, vals));
	ret = res;
	while (*str)
	{
		if (*str == '\'')
		{
			*(res++) = *(str++);
			while (*str && *str != '\'')
				*(res++) = *(str++);
			
		}
		if (get_name(str))
		{
			// printf("found name  %s \n", get_env(env, get_name(str)));
			ft_strlcpy(res, (*vals)->data, ft_strlen((*vals)->data) + 1);
			// ft_strlcpy(res, get_env(env, get_name(str)), ft_strlen(get_env(env, get_name(str))) + 1);
			move_res_str(&res, &str, get_name(str), (*vals)->data);
			// res += ft_strlen((*vals)->data);
			// str += ft_strlen(get_name(str)) + 1;
			// printf("res %s \n", res);
			// printf("str %s \n", str);
			*vals = (*vals)->next;
		}
		else if (*str)
			*(res++) = *(str++);
	}
	return (ret);
}
