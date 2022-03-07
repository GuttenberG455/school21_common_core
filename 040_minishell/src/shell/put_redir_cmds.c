/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_redir_cmds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:35:53 by rusty             #+#    #+#             */
/*   Updated: 2022/03/02 15:05:40 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	put_redir_cmds(t_shell *shell)
{
	int	i;

	i = -1;
	while (++i < shell->cmds_count)
		if (parse_redir(shell->cmds_arr[i]) || \
		parse_commands(shell->cmds_arr[i]))
			return (1);
	return (0);
}
