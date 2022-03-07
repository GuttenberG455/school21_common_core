/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:23:49 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/04 12:42:05 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	new_envp_del(t_env *env, char **tmp, char *param)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	param = ft_strjoin(param, "=");
	while (j < env->len)
	{
		if (ft_strncmp(ft_substr(env->envp[j], 0, ft_strchr(env->envp[j], '=')
					- env->envp[j] + 1), param, ft_strlen(param)) != 0)
		{
			tmp[i] = env->envp[j];
			i++;
			j++;
		}
		else
			j++;
	}
}

int	del_env(t_env *env, char *param)
{
	char	**tmp;

	if (!env || !param || !env->envp)
		return (1);
	if (env_par_exist(env, param))
	{
		tmp = ft_zalloc(sizeof(char *) * (env->len));
		new_envp_del(env, tmp, param);
		env->len--;
		env->envp = tmp;
	}
	return (0);
}
