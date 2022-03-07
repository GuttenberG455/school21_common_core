/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:52:33 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/03 16:06:24 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	export_par(t_env *env, char *str)
{
	char	*par;
	char	*val;

	if (str[0] == '=')
		return (err_ext_return_one(M_EXP, "`=\'", ERR_NOT_VAL));
	if (!strchr(str, '='))
	{
		par = ft_strtrim(str, " ");
		val = ft_strdup("");
	}
	else
	{
		par = ft_substr(str, 0, ft_strchr(str, '=') - str);
		val = ft_strtrim(ft_strchr(str, '=') + 1, " ");
	}
	if (check_env_par(par))
		return (err_ext_return_one(M_EXP, par, ERR_NOT_VAL));
	return (set_env(env, par, val));
}

char	*strdup_exp(const char *s1)
{
	char		*ret;
	size_t		len;
	size_t		i;

	i = 0;
	len = ft_strlen(s1);
	ret = ft_zalloc(sizeof(char) * (len + 1 + 2));
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, s1, len);
	ret[len + 1] = '\"';
	while (ret[i] && ret[i] != '=')
		i++;
	i++;
	while (len > i)
	{
		ret[len] = ret[len - 1];
		len--;
	}
	ret[len] = '\"';
	check_empty_exp(ret);
	return (ret);
}

void	sort_tmp_env(t_env *env)
{
	int		i;
	int		j;
	int		min;
	char	*tmp;

	i = 0;
	while (i < env->len - 1)
	{
		min = i;
		j = i + 1;
		while (j < env->len)
		{
			if (ft_strncmp(env->envp[j], env->envp[min], \
			ft_strlen(env->envp[min])) < 0)
				min = j;
			j++;
		}
		tmp = env->envp[i];
		env->envp[i] = env->envp[min];
		env->envp[min] = tmp;
		i++;
	}
}

void	show_export_list(t_env *env)
{
	int		i;
	t_env	*tmp_env;

	tmp_env = ft_zalloc(sizeof(t_env) * env->len);
	tmp_env->len = env->len;
	i = -1;
	tmp_env->envp = ft_zalloc(sizeof(char **) * (tmp_env->len + 1));
	while (++i < tmp_env->len)
		tmp_env->envp[i] = strdup_exp(env->envp[i]);
	sort_tmp_env(tmp_env);
	i = 0;
	while (i < env->len)
	{
		if (!ft_strnstr(tmp_env->envp[i], "_=", 2)
			&& !ft_strnstr(tmp_env->envp[i], "?=", 2))
			printf("declare -x %s\n", tmp_env->envp[i]);
		i++;
	}
}

int	cmd_export(char **args, t_env *env)
{
	int		i;

	i = 0;
	if (args && !args[0])
		show_export_list(env);
	while (args && args[i])
	{
		export_par(env, args[i]);
		i++;
	}
	return (0);
}
