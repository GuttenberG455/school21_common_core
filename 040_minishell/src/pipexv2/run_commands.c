/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 04:19:49 by rusty             #+#    #+#             */
/*   Updated: 2022/03/04 05:51:34 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pre_exec_cmd(t_cmd *cmd, t_shell *shell)
{
	int	err;

	signal(SIGQUIT, handler_child_quit);
	if (dup2(cmd->fd[0], 0) == -1 || dup2(cmd->fd[1], 1) == -1)
	{
		err = errno;
		close_all(shell);
		err_exit_txt(M_SH, "dup2", strerror(err), 1);
	}
	close_all(shell);
	if (cmd->cmd_name)
	{
		if (is_cmd(cmd->cmd_name))
			run_cmd(cmd, shell->env);
		if (!ft_strncmp(cmd->cmd_name, "exit", ft_strlen("exit")))
			exit (0);
		exec_cmd(cmd, shell);
	}
	else
		exit(0);
}

void	run_multi_commands(t_shell *shell)
{
	int	i;

	i = -1;
	while (++i < shell->cmds_count)
	{
		shell->cmds_arr[i]->pid = fork();
		if (shell->cmds_arr[i]->pid == -1)
			perror("minishell: fork");
		else if (shell->cmds_arr[i]->pid > 0)
		{
			signal(SIGINT, sig_int_proc);
			signal(SIGQUIT, sig_int_proc);
			shell->pid_c = shell->cmds_arr[i]->pid;
		}
		else if (shell->cmds_arr[i]->pid == 0)
			pre_exec_cmd(shell->cmds_arr[i], shell);
	}
}
