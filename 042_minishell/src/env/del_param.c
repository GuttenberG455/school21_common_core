/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:23:49 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/23 12:43:00 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	new_envp_del(t_env *old_env, char **tmp, char *param)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < old_env->len)
	{
		if (ft_strncmp(old_env->envp[j], param, ft_strlen(param)) != 0)
		{
			tmp[i] = old_env->envp[j];
			i++;
			j++;
		}
		else
			j++;
	}
}

int	del_env_par(t_env *env, char *param)
{
	char	**tmp;

	if (!env || !param || !env->envp)
		return (err_return_one(M_ENV, ERR_NULL_PARAMS));
	if (env_par_exist(env, param))
	{
		tmp = ft_zalloc(sizeof(char *) * (env->len));
		new_envp_del(env, tmp, param);
		env->len--;
		env->envp = tmp;
	}
	return (0);
}
