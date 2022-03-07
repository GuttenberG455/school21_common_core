/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:27:12 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/04 12:42:20 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*get_env(t_env *env, char *param)
{
	int		i;
	char	*value;

	if (!env || !param || !env->envp)
		return (NULL);
	i = 0;
	param = ft_strjoin(param, "=");
	while (env->envp[i])
	{
		if (ft_strncmp(ft_substr(env->envp[i], 0, ft_strchr(env->envp[i], '=')
					- env->envp[i] + 1), param, ft_strlen(param)) == 0)
		{
			value = ft_strdup(ft_strchr(env->envp[i], '=') + 1);
			return (value);
		}
		i++;
	}
	return (ft_strdup(" "));
}
