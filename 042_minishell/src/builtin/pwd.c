/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:43:34 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/23 15:59:20 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	cmd_pwd(char **args, t_env *env)
{
	char	*value;

	(void *) args;
	if (!env || !env->envp)
		return (err_return_one(M_ENV, ERR_NO_ENV));
	value = get_env_par(env, "PWD");
	if (!value)
		return (err_return_one(M_ENV, ERR_NO_ENV));
	ft_putstr_fd(value, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
