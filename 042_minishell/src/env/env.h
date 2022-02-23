/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:20:36 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/23 12:54:46 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

#include "../libftv2/libftv2.h"
#include "../error/error.h"
#include "../const.h"

typedef struct s_env
{
	int		len;
	char	**envp;
}		t_env;

t_env	*init_env(char **envp);
char	*get_env_par(t_env *env, char *param);
int		set_env_par(t_env *env, char *param, char *value);
int		del_env_par(t_env *env, char *param);
int		env_par_exist(t_env *env, char *param);

#endif