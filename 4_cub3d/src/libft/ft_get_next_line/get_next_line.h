/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:57:58 by majacqua          #+#    #+#             */
/*   Updated: 2022/07/25 13:59:00 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include "../libft.h"

# define BUFFER_SIZE 64

char	*gnl_strchr(const char *s, int c);
size_t	gnl_strlen(const char *s);
void	*gnl_memmove(void *dest, const void *src, size_t n);
char	*gnl_strjoin(char const *s1, char const *s2);

#endif