/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:15:04 by majacqua          #+#    #+#             */
/*   Updated: 2021/11/16 16:19:21 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_GRID_H
# define GET_GRID_H

# include <unistd.h>
# include <fcntl.h>

size_t	ft_strlen(char *str);
int		ft_islinebreak(const char *str);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2);

int		get_next_line(int fd, char **map);

#endif