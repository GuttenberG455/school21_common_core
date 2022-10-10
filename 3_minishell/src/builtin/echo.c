/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:25:18 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/02 14:44:11 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	print_args(char **args, int i)
{
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
}

int	cmd_echo(char **args, t_env *env)
{
	(void)env;
	if (args[0] && ft_strncmp(args[0], "-n", 2) == 0)
		print_args(args, 1);
	else
	{
		print_args(args, 0);
		ft_putchar_fd('\n', 1);
	}
	return (0);
}
