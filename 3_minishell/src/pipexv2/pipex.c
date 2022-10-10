/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:34:16 by rusty             #+#    #+#             */
/*   Updated: 2022/03/04 04:21:53 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_last_status(t_shell *shell, t_cmd *child, int wstat)
{
	if (WIFEXITED(wstat))
		set_env(shell->env, "?", ft_itoa(WEXITSTATUS(wstat)));
	else if (WIFSIGNALED(wstat))
		set_env(shell->env, "?", ft_itoa(WTERMSIG(wstat) + 128));
	set_env(shell->env, "_", child->cmd_name);
}

t_cmd	*who_returned(t_shell *shell, int pid)
{
	int	i;

	i = -1;
	while (++i < shell->cmds_count)
	{
		if (shell->cmds_arr[i]->pid == pid)
			return (shell->cmds_arr[i]);
	}
	return (NULL);
}

void	wait_all_children(t_shell *shell)
{
	int			i;
	int			ret;
	int			wstat;
	t_cmd		*cmd;

	i = -1;
	wstat = 0;
	while (++i < shell->cmds_count)
	{
		ret = waitpid(0, &wstat, 0);
		cmd = who_returned(shell, ret);
		set_last_status(shell, cmd, wstat);
		if (cmd)
		{
			if (cmd->fd[0] != 0)
				close(cmd->fd[0]);
			if (cmd->fd[1] != 1)
				close(cmd->fd[1]);
		}
	}
}

void	pipex(t_shell *shell)
{
	if (shell->cmds_count == 1 && is_nofork(shell->cmds_arr[0]->cmd_name))
	{
		run_nofork(shell->cmds_arr[0], shell->env);
		return ;
	}
	else
		run_multi_commands(shell);
	wait_all_children(shell);
}
