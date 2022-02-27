/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:00:36 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/27 14:31:31 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	is_cmd(char *str)
{
	if (ft_strcmp(str, "cd") == 0)
		return (1);
	else if (ft_strcmp(str, "echo") == 0)
		return (1);
	else if (ft_strcmp(str, "env") == 0)
		return (1);
	else if (ft_strcmp(str, "export") == 0)
		return (1);
	else if (ft_strcmp(str, "pwd") == 0)
		return (1);
	else if (ft_strcmp(str, "unset") == 0)
		return (1);
	return (0);
}

int	run_cmd(t_cmd *cmd, t_env *env)
{
	int	status;

	status = 0;
	if (ft_strcmp(cmd->cmd, "cd") == 0)
		status = cmd_cd(cmd->args + 1, env);
	else if (ft_strcmp(cmd->cmd, "echo") == 0)
		status = cmd_echo(cmd->args + 1, env);
	else if (ft_strcmp(cmd->cmd, "env") == 0)
		status = cmd_env(cmd->args + 1, env);
	else if (ft_strcmp(cmd->cmd, "export") == 0)
		status = cmd_export(cmd->args + 1, env);
	else if (ft_strcmp(cmd->cmd, "pwd") == 0)
		status = cmd_pwd(cmd->args + 1, env);
	else if (ft_strcmp(cmd->cmd, "unset") == 0)
		status = cmd_unset(cmd->args + 1, env);
	ft_free();
	exit(status);
}
