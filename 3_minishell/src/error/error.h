/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:53:07 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/05 17:37:00 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "../libftv2/libft/libft.h"
# include "../const.h"
# include "stdio.h"

int		err_return_one(char *module, char *text);
void	*err_return_null(char *module, char *text);
int		err_return_zero(char *module, char *type);
int		err_return_zero(char *module, char *type);

int		err_ext_return_one(char *module, char *text, char *name);
int		err_exit(char *module, char *cmd, int ex_status);
int		err_exit_txt(char *module, char *text, char *name, int status);

int		here_doc_warning(char *lim);

#endif