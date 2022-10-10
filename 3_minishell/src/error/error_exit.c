/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:31:07 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/05 19:00:30 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int	err_ext_return_one(char *module, char *text, char *name)
{
	ft_putstr_fd(module, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(text, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

int	err_exit(char *module, char *cmd, int ex_status)
{
	ft_putstr_fd(module, 2);
	ft_putstr_fd(": ", 2);
	perror(cmd);
	ft_free();
	exit(ex_status);
}

int	err_exit_txt(char *module, char *text, char *name, int status)
{
	ft_putstr_fd(module, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(text, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("\n", 2);
	ft_free();
	exit(status);
}

int	here_doc_warning(char *lim)
{
	ft_putstr_fd(" ", 2);
	ft_putstr_fd(M_SH, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd("warning: here-document at line\
delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(lim, 2);
	ft_putstr_fd("')", 2);
	ft_putstr_fd("\n", 2);
	return (0);
}
