/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:26:01 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/03 16:07:08 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../env/env.h"
# include "../error/error.h"
# include "../commands/commands.h"
# include "../const.h"

# include <limits.h>

int		cmd_echo(char **args, t_env *env);
int		cmd_cd(char **args, t_env *env);
int		cmd_pwd(char **args, t_env *env);
int		cmd_env(char **args, t_env *env);
int		cmd_unset(char **args, t_env *env);
int		cmd_export(char **args, t_env *env);

int		is_cmd(char *str);
int		run_cmd(t_cmd *cmd, t_env *env);
int		is_nofork(char *cmd);
int		run_nofork(t_cmd *cmd, t_env *env);	

int		check_env_par(char *param);
void	check_empty_exp(char *str);

#endif