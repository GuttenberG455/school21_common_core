/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:58:30 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/14 13:41:12 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

size_t	ft_strlen(char *str);
int		ft_islinebreak(const char *str);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2);

#endif 