/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:23:25 by majacqua          #+#    #+#             */
/*   Updated: 2022/05/06 18:48:42 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

# include <limits.h>

# include "../env/env.h"
# include "../error/error.h"

void check_input(int argc, char **argv);
t_map *get_map(char *argv);

#endif