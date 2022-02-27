/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 07:38:49 by rusty             #+#    #+#             */
/*   Updated: 2022/02/26 18:46:19 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H
# define CONST_H

/* GENERAL */
# define PROMPT "¯\\_(ツ)_/¯:"

/* MODULES */
# define M_ENV	"Environment"
# define M_PAR	"Parser"
# define M_CD	"cd"
# define M_PWD	"pwd"
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

/* ASCII */
# define ASCII_ACK	6

#endif