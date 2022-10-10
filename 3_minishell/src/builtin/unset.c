/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:51:53 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/03 16:07:12 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	check_empty_exp(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	if ((str[i] == '\"') && (str[i - 1] == '\"'))
	{
		str[i] = '\0';
		str[i - 1] = '\0';
	}
}

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

	if (!args || !args[0])
		return (err_return_one(M_UNS, ERR_NE_ARGS));
	i = 0;
	while (args[i])
	{
		if (check_env_par(args[i]))
			err_ext_return_one(M_UNS, args[i], ERR_NOT_VAL);
		else if (env_par_exist(env, args[i]))
			del_env(env, args[i]);
		i++;
	}
	return (0);
}
