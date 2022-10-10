/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:09:40 by rusty             #+#    #+#             */
/*   Updated: 2022/03/04 14:47:52 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "../redirect/redirect.h"
# include "../libftv2/libftv2.h"
# include "../error/error.h"

typedef struct s_cmd	t_cmd;

struct	s_cmd
{
	int		pid;
	char	*input;
	char	*cmd_name;
	char	**args;
	int		fd[2];
	t_redir	*left;
	t_redir	*right;
};

int	put_redir(t_cmd *cmd, char *str);

#endif