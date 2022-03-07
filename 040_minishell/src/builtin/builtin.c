/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:00:36 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/04 19:34:05 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	is_cmd(char *str)
{
	if (ft_strncmp(str, "cd", ft_strlen(str)) == 0)
		return (1);
	else if (ft_strncmp(str, "echo", ft_strlen(str)) == 0)
		return (1);
	else if (ft_strncmp(str, "env", ft_strlen(str)) == 0)
		return (1);
	else if (ft_strncmp(str, "export", ft_strlen(str)) == 0)
		return (1);
	else if (ft_strncmp(str, "pwd", ft_strlen(str)) == 0)
		return (1);
	else if (ft_strncmp(str, "unset", ft_strlen(str)) == 0)
		return (1);
	return (0);
}

int	run_cmd(t_cmd *cmd, t_env *env)
{
	int	status;

	status = 0;
	if (ft_strncmp(cmd->cmd_name, "cd", ft_strlen(cmd->cmd_name)) == 0)
		status = cmd_cd(cmd->args + 1, env);
	else if (ft_strncmp(cmd->cmd_name, "echo", ft_strlen(cmd->cmd_name)) == 0)
		status = cmd_echo(cmd->args + 1, env);
	else if (ft_strncmp(cmd->cmd_name, "env", ft_strlen(cmd->cmd_name)) == 0)
		status = cmd_env(cmd->args + 1, env);
	else if (ft_strncmp(cmd->cmd_name, "export", ft_strlen(cmd->cmd_name)) == 0)
		status = cmd_export(cmd->args + 1, env);
	else if (ft_strncmp(cmd->cmd_name, "pwd", ft_strlen(cmd->cmd_name)) == 0)
		status = cmd_pwd(cmd->args + 1, env);
	else if (ft_strncmp(cmd->cmd_name, "unset", ft_strlen(cmd->cmd_name)) == 0)
		status = cmd_unset(cmd->args + 1, env);
	ft_free();
	exit(status);
}

int	is_nofork(char *cmd)
{
	if (!cmd)
		return (1);
	if (ft_strncmp(cmd, "cd", ft_strlen("cd")) == 0)
		return (1);
	else if (ft_strncmp(cmd, "unset", ft_strlen("unset")) == 0)
		return (1);
	else if (ft_strncmp(cmd, "export", ft_strlen("export")) == 0)
		return (1);
	return (0);
}

int	run_nofork(t_cmd *cmd, t_env *env)
{
	int	status;

	if (!cmd->cmd_name)
		return (1);
	status = 0;
	if (ft_strncmp(cmd->cmd_name, "cd", ft_strlen("cd")) == 0)
		status = cmd_cd(cmd->args + 1, env);
	else if (ft_strncmp(cmd->cmd_name, "unset", ft_strlen("unset")) == 0)
		status = cmd_unset(cmd->args + 1, env);
	else if (ft_strncmp(cmd->cmd_name, "export", ft_strlen("export")) == 0)
		status = cmd_export(cmd->args + 1, env);
	set_env(env, "_", cmd->cmd_name);
	set_env(env, "?", ft_itoa(status));
	return (status);
}
