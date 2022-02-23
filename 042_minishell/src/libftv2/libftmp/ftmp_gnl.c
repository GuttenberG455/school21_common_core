/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmp_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:55:17 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/22 14:57:34 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmp.h"

char	*ftmp_substr_gnlb(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	sze;

	if (s == NULL)
		return (NULL);
	if ((size_t) start >= ftmp_strlen_gnlb(s))
	{
		ret = ftmp_zalloc(1 * sizeof(char));
		if (ret == NULL)
			return (NULL);
		ret[0] = '\0';
		return (ret);
	}
	if (ftmp_strlen_gnlb(s + start) < len)
		sze = ftmp_strlen_gnlb(s + start);
	else
		sze = len;
	ret = ftmp_zalloc((sze + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ftmp_strlcpy_gnlb(ret, s + start, sze + 1);
	return (ret);
}

char	*ftmp_readline_gnlb(char **tail, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int		rd;
	char	*new_tail;

	rd = 1;
	while (rd && !ftmp_strchr_gnlb(*tail, '\n'))
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd < 0)
			return (NULL);
		buff[rd] = '\0';
		new_tail = ftmp_strjoin_gnlb(*tail, buff);
		if (!new_tail)
			return (NULL);
		if (*tail)
		{
			free(*tail);
			*tail = 0;
		}
		*tail = new_tail;
	}
	return (*tail);
}

char	*ftmp_newtail_gnlb(char **tail)
{
	char	*pt;
	char	*tmp;

	if (*tail)
	{
		pt = ftmp_strchr_gnlb(*tail, '\n');
		if (!pt)
		{
			free(*tail);
			*tail = 0;
		}
		else
		{
			++pt;
			tmp = ftmp_substr_gnlb(*tail, 0, ftmp_strchr_gnlb(*tail, '\0') - *tail);
			free(*tail);
			*tail = 0;
			*tail = ftmp_substr_gnlb(ftmp_strchr_gnlb(tmp, '\n') + 1, 0, \
ftmp_strchr_gnlb(*tail, '\0') - ftmp_strchr_gnlb(tmp, '\n') + 1);
			if (tmp)
				free(tmp);
		}
		return (*tail);
	}
	return (NULL);
}

char	*ftmp_workline_gnlb(char *tail)
{
	char	*pt;
	char	*ret;

	if (tail)
	{
		if (!tail[0])
			return (NULL);
		pt = ftmp_strchr_gnlb(tail, '\n');
		if (!pt)
			ret = ftmp_substr_gnlb(tail, 0, ftmp_strchr_gnlb(tail, '\0') - tail);
		else
		{
			++pt;
			ret = ftmp_substr_gnlb(tail, 0, pt - tail);
		}
		return (ret);
	}
	return (NULL);
}

char	*ftmp_get_next_line(int fd)
{
	static char	*tail[11000];
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tail[fd] = ftmp_readline_gnlb(&tail[fd], fd);
	ret = ftmp_workline_gnlb(tail[fd]);
	tail[fd] = ftmp_newtail_gnlb(&tail[fd]);
	return (ret);
}

