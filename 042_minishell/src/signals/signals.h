/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 02:28:19 by rusty             #+#    #+#             */
/*   Updated: 2022/02/18 02:29:33 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include <signal.h>
# include <unistd.h>
# include <readline.h>

// int		check_int_skip(t_shell *shell, char *read);
int		check_exit_ctrl_d(char *read);
void	sig_int_empty(int signum);
void	sig_int_proc(int signum);

#endif