/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:12:34 by rusty             #+#    #+#             */
/*   Updated: 2022/03/04 05:39:07 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../commands/commands.h"
# include "../redirect/redirect.h"
# include "../libftv2/libftv2.h"
# include "../error/error.h"
# include "../env/env.h"

char	*cut_spaces(char *input);
char	*put_global(t_env *env, char *str);
char	**parse_pipes(char *input);

int		parse_commands(t_cmd *cmd);
int		parse_redir(t_cmd *cmd);

void	skip_sing_quote(char *str, int *i);
void	skip_quotes_int(char *str, int *i);
void	skip_quotes_str(char **str, char **res);

#endif