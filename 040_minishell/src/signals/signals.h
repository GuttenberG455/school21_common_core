/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 02:28:19 by rusty             #+#    #+#             */
/*   Updated: 2022/03/05 18:19:55 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include "../shell/shell.h"
# include "../libftv2/libftv2.h"

int		check_exit_eof(char *read);
void	handler_child_quit(int signum);
void	sig_int_empty(int signum);
void	sig_int_proc(int signum);

#endif