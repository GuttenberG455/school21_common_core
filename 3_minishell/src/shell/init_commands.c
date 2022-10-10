/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:52:38 by rusty             #+#    #+#             */
/*   Updated: 2022/03/05 17:25:32 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	ft_isstrdigit(char *str)
{
	if (!str)
		return (1);
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v'\
	|| *str == '\f' || *str == '\r')
		++str;
	if (*str == '+' || *str == '-')
		++str;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		if (*str)
			++str;
	}
	return (1);
}

void	check_exit_str(t_shell *shell)
{
	int		i;
	char	**sp;

	i = 0;
	if (shell->cmds_count != 1)
		return ;
	sp = ft_split(shell->cmds_arr[0]->input, ' ');
	while (sp && sp[i])
		i++;
	if (sp && sp[0] && !ft_strncmp(sp[0], "exit", ft_strlen("exit")))
	{
		shell->exit = 1;
		if (i > 1)
			shell->exit_status = ft_atoi(sp[1]);
		if (i > 1 && (!ft_isstrdigit(sp[1]) || less_mll(sp[1])))
		{
			err_return_one(M_EXIT, " numeric argument required");
			shell->exit_status = 255;
		}
		else if (i > 2)
		{
			shell->exit = 0;
			err_return_one(M_EXIT, ERR_MN_ARGS);
		}
	}
}

t_cmd	*init_cmd(char *cmd)
{
	t_cmd	*ret;

	ret = ft_zalloc(sizeof(t_cmd));
	ret->input = ft_strtrim(cmd, " ");
	ret->fd[0] = 0;
	ret->fd[1] = 1;
	return (ret);
}

int	nord_stream(t_shell *shell)
{
	int	i;
	int	fd[2];

	i = 0;
	while (++i < shell->cmds_count)
	{
		if (pipe(fd) < 0)
			return (err_ext_return_one(M_SH, "pipe", strerror(errno)));
		shell->cmds_arr[i]->fd[0] = fd[0];
		shell->cmds_arr[i - 1]->fd[1] = fd[1];
	}
	return (0);
}

int	init_commands(t_shell *shell, char **parsed)
{
	int	i;

	shell->cmds_arr = ft_zalloc(sizeof(t_cmd *) * shell->cmds_count);
	i = -1;
	while (++i < shell->cmds_count)
		shell->cmds_arr[i] = init_cmd(parsed[i]);
	if (nord_stream(shell) || put_redir_cmds(shell))
		return (1);
	return (0);
}
