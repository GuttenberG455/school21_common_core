/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:26:01 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/23 15:47:38 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../env/env.h"
# include "../error/error.h"
# include "../const.h"

int	cmd_env(char **args, t_env *env);
int	cmd_pwd(char **args, t_env *env);

#endif