/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:19:39 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/02 17:13:51 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	args_length(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	cmd_cd(char **args, t_env *env)
{
	char	*tmp;
	char	tmp_wd[PATH_MAX];
	int		status;

	if (args_length(args) == 0)
		return (0);
	if (args_length(args) > 1)
		return (err_return_one(M_CD, ERR_MN_ARGS));
	if (chdir(args[0]) == -1)
		return (err_ext_return_one(M_CD, ERR_NO_FILE, args[0]));
	status = 0;
	tmp = get_env(env, "PWD");
	if (set_env(env, "OLDPWD", tmp))
		status = 1;
	getcwd(tmp_wd, PATH_MAX);
	if (set_env(env, "PWD", tmp_wd))
		status = 1;
	return (status);
}
