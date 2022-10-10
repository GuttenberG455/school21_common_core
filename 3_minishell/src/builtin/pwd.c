/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:43:34 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/28 03:47:19 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	cmd_pwd(char **args, t_env *env)
{
	char	*value;

	if (!env || !env->envp)
		return (err_return_one(M_ENV, ERR_NO_ENV));
	if (args && args[0])
		return (err_return_one(M_PWD, ERR_MN_ARGS));
	value = get_env(env, "PWD");
	if (!value)
		return (err_return_one(M_ENV, ERR_NO_ENV));
	ft_putstr_fd(value, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
