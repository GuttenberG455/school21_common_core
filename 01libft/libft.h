/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:54:16 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/07 14:30:14 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

int		ft_isalpha(int ch); // 1 OK
int		ft_isdigit(int ch); // 2 OK
int		ft_isalnum(int ch); // 3 OK
int		ft_isascii(int ch); // 4 OK
int		ft_isprint(int ch); // 5 OK
size_t	ft_strlen(char *str); // 6 OK
void	*ft_memset(void *memptr, int val, size_t size); // 7 OK
void	ft_bzero(void *ptr, size_t size); // 8 OK 
void	*ft_memcpy(void *destptr, const void *srcptr, size_t num); // 9 OK
void	*ft_memmove(void *dest, const void *src, size_t size); // 10 OK
size_t	ft_strlcpy(char *dest, const char *src, size_t size); // 11 -
size_t	ft_strlcat(char *dest, const char *src, size_t size); // 12 OK
int		ft_toupper(int ch); // 13 OK
int		ft_tolower(int ch); // 14 OK
char	*ft_strchr(const char *str, int sym); // 15 OK
char	*ft_strrchr(const char *str, int sym); // 16 OK 
int		ft_strncmp(char *s1, char *s2, size_t n); // 17 OK
void	*ft_memchr(const void *memptr,	int val, size_t size); // 18 OK
int		ft_memcmp(const void *memptr1, const void *memptr2, size_t size); // 19 OK
char	*ft_strnstr(const char *big, const char *little, size_t size); // 20 OK
int		ft_atoi(const char *str); // 21 OK
char	*ft_strdup(char *src); // 22 OK
void	*ft_calloc(size_t number, size_t size); //23

char	*ft_substr(char const *s, unsigned int start, size_t size); // 101 -
char	*ft_strjoin(char const *s1, char const *s2); // 102 OK
char	*ft_strtrim(char const *s1, char const *set); // 103 OK
char	**ft_split(char const *s, char sep); //104 OK
char	*ft_itoa(int n); // 105 -
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char)); // OK
void	ft_striteri(char *s, void (*f)(unsigned int, char*)); // OK
void	ft_putchar_fd(char c, int fd); // 108 OK
void	ft_putstr_fd(char *s, int fd); // 109 OK
void	ft_putendl_fd(char *s, int fd); // 110 OK
void	ft_putnbr_fd(int n, int fd); //111 OK

#endif