/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 02:25:41 by rusty             #+#    #+#             */
/*   Updated: 2022/03/05 16:26:36 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

int	check_exit_eof(char *read)
{
	if (!read)
	{
		write(2, "exit\n", 5);
		return (1);
	}
	return (0);
}

void	handler_child_quit(int signum)
{
	if (signum == SIGQUIT)
		exit(131);
}

void	sig_int_empty(int signum)
{
	if (signum == SIGINT)
	{
		write(2, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	sig_int_proc(int signum)
{
	t_shell	*shell;

	shell = (t_shell *)g_heap.shell;
	if (signum == SIGINT)
	{
		kill(shell->pid_c, SIGINT);
		write(1, "\n", 1);
	}
	if (signum == SIGQUIT)
	{
		kill(shell->pid_c, SIGINT);
		write(1, "Quit (core dumped)\n", 19);
		signal(SIGQUIT, SIG_IGN);
	}
}
