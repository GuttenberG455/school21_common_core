/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 04:13:54 by rusty             #+#    #+#             */
/*   Updated: 2022/03/05 18:54:57 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_not_dir(char *full_cmd)
{
	DIR	*dir;

	dir = opendir(full_cmd);
	if (dir)
	{
		closedir(dir);
		return (1);
	}
	return (0);
}

char	*find_path(char **paths, char *cmd)
{
	int		i;
	char	*name;

	i = -1;
	if (check_not_dir(cmd))
		err_exit_txt(M_SH, cmd, ERR_IS_DIREC, 126);
	while (paths[++i])
	{
		if (paths[i][ft_strlen(paths[i]) - 1] != '/')
			name = ft_multi_join(3, paths[i], "/", cmd);
		else
			name = ft_strjoin(paths[i], cmd);
		if (!access(name, F_OK))
			return (name);
	}
	err_exit_txt(M_SH, cmd, ERR_NO_COMM, 127);
	return (cmd);
}

char	*add_pwd(char *pwd, char *cmd)
{
	if (!pwd)
		return (cmd);
	if (pwd[ft_strlen(pwd) - 1] != '/')
	{
		if (cmd[0] != '/')
			return (ft_multi_join(3, pwd, "/", cmd));
		else
			return (ft_strjoin(pwd, cmd));
	}
	else
	{
		if (cmd[0] != '/')
			return (ft_strjoin(pwd, cmd));
		else
			return (ft_strjoin(pwd, cmd + 1));
	}
	return (NULL);
}

void	close_all(t_shell *shell)
{
	int	i;

	i = -1;
	while (++i < shell->cmds_count)
	{
		if (shell->cmds_arr[i]->fd[0] != 0)
			close(shell->cmds_arr[i]->fd[0]);
		if (shell->cmds_arr[i]->fd[1] != 1)
			close(shell->cmds_arr[i]->fd[1]);
	}
}

void	exec_cmd(t_cmd *cmd, t_shell *shell)
{
	char	*full_cmd;

	if (cmd->cmd_name[0] == '.')
		full_cmd = add_pwd(get_env(shell->env, "PWD"), cmd->cmd_name);
	else
		full_cmd = find_path(ft_split(get_env(shell->env, "PATH"), ':'), \
		cmd->cmd_name);
	if (check_not_dir(full_cmd))
		err_exit_txt(M_SH, cmd->cmd_name, ERR_IS_DIREC, 126);
	if (access(full_cmd, F_OK) == -1)
		err_exit_txt(M_SH, cmd->cmd_name, ERR_NO_COMM, 127);
	if (access(full_cmd, X_OK) == -1)
		err_exit(M_SH, cmd->cmd_name, 126);
	execve(full_cmd, cmd->args, shell->env->envp);
	ft_free();
	exit (127);
}
