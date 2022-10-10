/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:19:05 by rusty             #+#    #+#             */
/*   Updated: 2022/03/05 17:11:23 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <errno.h>
# include <limits.h>
# include "../commands/commands.h"
# include "../parser/parser.h"
# include "../redirect/redirect.h"
# include "../env/env.h"

typedef struct s_shell	t_shell;

struct s_shell
{
	int				pid_c;
	char			*input;
	t_env			*env;
	int				cmds_count;
	t_cmd			**cmds_arr;
	int				cmds;
	int				exit;
	unsigned char	exit_status;
};

int		put_redir_cmds(t_shell *shell);
int		init_commands(t_shell *shell, char **parsed);
void	check_exit_str(t_shell *shell);
int		less_mll(const char *str);

#endif