/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 07:38:49 by rusty             #+#    #+#             */
/*   Updated: 2022/03/04 19:24:16 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H
# define CONST_H

/* GENERAL */
# define PROMPT "ba$h> "

/* MODULES */
# define M_SH	"ba$h"
# define M_ENV	"environment"
# define M_PAR	"parser"
# define M_CD	"ba$h: cd"
# define M_PWD	"ba$h: pwd"
# define M_EXIT	"ba$h: exit"
# define M_UNS	"unset"
# define M_EXP	"export"

/* ERRORS */
# define ERR_NULL_PARAMS	"some parameters are NULL"
# define ERR_NO_ENV			"env file is corrupted"
# define ERR_MN_ARGS		"too many arguments"
# define ERR_NO_FILE		"no such file or directory"
# define ERR_NE_ARGS		"not enough arguments"
# define ERR_INV_PAR		"invalid parameter name"
# define ERR_NOT_A_I		"not an identifier"
# define ERR_NOT_VAL		"not a valid identifier"
# define ERR_IS_DIREC		"is a directory"
# define ERR_NO_COMM		"command not found"

#endif
