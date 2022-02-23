/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftmp.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:47:59 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/23 14:45:41 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTMP_H
# define LIBFTMP_H

# include "../ft_zalloc/ft_zalloc.h"

typedef struct s_list	t_list;

void	*ftmp_memcpy_gnlb(void *dst, const void *src, size_t n);
char	*ftmp_strjoin_gnlb(char *s1, char *s2);
char	*ftmp_strchr_gnlb(const char *s, int c);
size_t	ftmp_strlen_gnlb(const char *s);
size_t	ftmp_strlcpy_gnlb(char *dst, const char *src, size_t dstsize);
char	*ftmp_substr_gnlb(char const *s, unsigned int start, size_t len);
char	*ftmp_readline_gnlb(char **tail, int fd);
char	*ftmp_newtail_gnlb(char **tail);
char	*ftmp_workline_gnlb(char *tail);
char	*ftmp_get_next_line(int fd);

t_list	*ftmp_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ftmp_lstnew(void *content);
char	*ftmp_strmapi(char const *s, char (*f)(unsigned int, char c));
char	*ftmp_itoa(int n);
char	*ftmp_strdup(const char *s1);
char	*ftmp_substr(char const *s, unsigned int start, size_t len);
char	*ftmp_strjoin(char const *s1, char const *s2);
char	*ftmp_strtrim(char const *s1, char const *set);
char	**ftmp_split(char const *s, char c);
char	*ftmp_multi_join(const char *str, ...); // TODO

#endif