/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:51:53 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/26 18:38:59 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	check_env_par(char *param)
{
	int	i;

	i = 0;
	if (ft_strlen(param) == 0)
		return (0);
	if (!ft_isalpha(param[0]) && param[0] != '_')
		return (1);
	while (param[i])
	{
		if (!ft_isalnum(param[i]) && param[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

int	cmd_unset(char **args, t_env *env)
{
	int		i;
	char	*err_str;

	if (!args || !args[0])
		return (err_return_one(M_UNS, ERR_NE_ARGS));
	i = 0;
	while (args[i])
	{
		if (!err_str && check_env_par(args[i]))
			err_str = args[i];
		if (env_par_exist(env, args[i]))
			del_env_par(env, args[i]);
		i++;
	}
	if (err_str)
		return (err_ext_return_one(M_UNS, ERR_INV_PAR, err_str));
	return (0);
}
