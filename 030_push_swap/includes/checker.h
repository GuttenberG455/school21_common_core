/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:19:46 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/08 14:54:38 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

char	*get_next_line(int fd);

size_t	gnl_strlen(const char *str);
void	*gnl_memmove(void *dest, const void *src, size_t size);
int		gnl_islinebreak(const char *str);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_strdup(char *src);

int		do_instruction(t_env *env, char *str);

void	ft_print_list(t_lstack **stack);
void	ft_print_env(t_env *env);

#endif