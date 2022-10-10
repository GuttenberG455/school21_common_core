/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:31:19 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/02 14:39:46 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	cmd_env(char **args, t_env *env)
{
	int	i;

	if (!env || !env->envp)
		return (err_return_one(M_ENV, ERR_NO_ENV));
	i = 0;
	if (args && args[i] != NULL)
		return (err_return_one(M_ENV, ERR_MN_ARGS));
	while (i < env->len)
	{
		ft_putstr_fd(env->envp[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	return (0);
}
