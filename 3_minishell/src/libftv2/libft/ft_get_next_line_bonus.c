/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 19:34:14 by ubeetroo          #+#    #+#             */
/*   Updated: 2022/02/18 01:04:45 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_gnlb(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	sze;

	if (s == NULL)
		return (NULL);
	if ((size_t) start >= ft_strlen_gnlb(s))
	{
		ret = ft_zalloc(1 * sizeof(char));
		if (ret == NULL)
			return (NULL);
		ret[0] = '\0';
		return (ret);
	}
	if (ft_strlen_gnlb(s + start) < len)
		sze = ft_strlen_gnlb(s + start);
	else
		sze = len;
	ret = ft_zalloc((sze + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_strlcpy_gnlb(ret, s + start, sze + 1);
	return (ret);
}

char	*ft_readline_gnlb(char **tail, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int		rd;
	char	*new_tail;

	rd = 1;
	while (rd && !ft_strchr_gnlb(*tail, '\n'))
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd < 0)
			return (NULL);
		buff[rd] = '\0';
		new_tail = ft_strjoin_gnlb(*tail, buff);
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

char	*ft_newtail_gnlb(char **tail)
{
	char	*pt;
	char	*tmp;

	if (*tail)
	{
		pt = ft_strchr_gnlb(*tail, '\n');
		if (!pt)
		{
			free(*tail);
			*tail = 0;
		}
		else
		{
			++pt;
			tmp = ft_substr_gnlb(*tail, 0, ft_strchr_gnlb(*tail, '\0') - *tail);
			free(*tail);
			*tail = 0;
			*tail = ft_substr_gnlb(ft_strchr_gnlb(tmp, '\n') + 1, 0, \
ft_strchr_gnlb(*tail, '\0') - ft_strchr_gnlb(tmp, '\n') + 1);
			if (tmp)
				free(tmp);
		}
		return (*tail);
	}
	return (NULL);
}

char	*ft_workline_gnlb(char *tail)
{
	char	*pt;
	char	*ret;

	if (tail)
	{
		if (!tail[0])
			return (NULL);
		pt = ft_strchr_gnlb(tail, '\n');
		if (!pt)
			ret = ft_substr_gnlb(tail, 0, ft_strchr_gnlb(tail, '\0') - tail);
		else
		{
			++pt;
			ret = ft_substr_gnlb(tail, 0, pt - tail);
		}
		return (ret);
	}
	return (NULL);
}

char	*ft_get_next_line(int fd)
{
	static char	*tail[11000];
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tail[fd] = ft_readline_gnlb(&tail[fd], fd);
	ret = ft_workline_gnlb(tail[fd]);
	tail[fd] = ft_newtail_gnlb(&tail[fd]);
	return (ret);
}
