/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:51:53 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/23 15:59:17 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	cmd_unset(char **args, t_env *env)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (env_par_exist(env, args[i]))	// проверка на имя
			del_env_par(env, args[i]);
		i++;
	}
	return (0);
}
