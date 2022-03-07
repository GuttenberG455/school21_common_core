/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:18:06 by rusty             #+#    #+#             */
/*   Updated: 2022/03/05 16:25:17 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int	redir_error(char *str)
{
	char	*str_err;

	if (str && !str[0])
		return (err_return_one(M_SH, \
			"syntax error near unexpected token `newline\'"));
	else
	{
		str_err = ft_zalloc(3);
		str_err[0] = str[0];
		if ((str[1] == '>' || str[1] == '<')
			&& (str[0] != '>' || str[1] != '<'))
			str_err[1] = str[1];
		return (err_return_one(M_SH, ft_multi_join(3, \
			"syntax error near unexpected token `", str_err, "\'")));
	}
}

int	check_redir(char *str)
{
	if (ft_strchr("<>", *str) && ft_strlen(str) == 1)
	{
		return (err_return_one(M_SH, \
			"syntax error near unexpected token `newline\'"));
	}
	if (str[0] == '>' && str[1] == '<')
		return (redir_error(str + 1));
	if (!ft_strchr("<>", *str))
		return (1);
	if (ft_strchr("<>", *str))
		str++;
	if (ft_strchr("<>", *str))
		str++;
	while (*str == ' ')
		str++;
	if (ft_strchr("<>", *str))
	{
		return (redir_error(str));
	}
	return (0);
}

t_redir	*create_redir(char *str)
{
	t_redir	*new;

	if (check_redir(str))
		return (NULL);
	new = ft_zalloc(sizeof(t_redir));
	if (str[0] == '<' && str[1] == '<')
		new->type = IN_DOC;
	else if (str[0] == '>' && str[1] == '>')
		new->type = OUT_DOC;
	else if (str[0] == '<')
		new->type = IN;
	else if (str[0] == '>')
		new->type = OUT;
	while (*str && ft_strchr("<> ", *str))
		++str;
	new->file = ft_strdup(str);
	if (!new->file || open_file(new))
	{
		close(new->fd);
		return (NULL);
	}
	return (new);
}

int	put_redir(t_cmd *cmd, char *str)
{
	t_redir	*red;
	t_redir	**cur_redir;
	int		in_out;

	red = create_redir(str);
	if (!red)
		return (1);
	in_out = 1;
	cur_redir = &cmd->right;
	if (red->type == IN || red->type == IN_DOC)
	{
		in_out = 0;
		cur_redir = &cmd->left;
	}
	if (!cur_redir && cmd->fd[in_out] > 2)
		close(cmd->fd[in_out]);
	if (*cur_redir)
		close((*cur_redir)->fd);
	*cur_redir = red;
	if (cmd->left)
		cmd->fd[0] = cmd->left->fd;
	if (cmd->right)
		cmd->fd[1] = cmd->right->fd;
	return (0);
}
