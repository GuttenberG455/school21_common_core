/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:59:33 by majacqua          #+#    #+#             */
/*   Updated: 2022/07/25 13:59:42 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_move_to_nl(char	*rd)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!rd)
		return (NULL);
	while (rd[i] && rd[i] != '\n')
		i++;
	if (!rd[i])
		return (0);
	res = ft_zalloc(sizeof(char) * ((gnl_strlen(rd) - i) + 1));
	if (!res)
		return (0);
	i++;
	while (rd[i])
		res[j++] = rd[i++];
	res[j] = '\0';
	return (res);
}

char	*ft_getres(char *rd)
{
	char	*res;
	int		i;

	i = 0;
	if (rd[i] == '\0')
		return (NULL);
	while (rd[i] && rd[i] != '\n')
		i++;
	res = ft_zalloc(i + 2);
	if (!res)
		return (NULL);
	gnl_memmove(res, rd, i);
	res[i] = '\0';
	return (res);
}

char	*ft_get_buffer(int fd, char *buffer)
{
	char	buf[BUFFER_SIZE + 1];
	int		r;
	char	*tmp;

	r = read(fd, buf, BUFFER_SIZE);
	while (r > 0)
	{
		buf[r] = '\0';
		tmp = buffer;
		buffer = gnl_strjoin(tmp, buf);
		if (gnl_strchr(buffer, '\n'))
		{
			break ;
		}
		r = read(fd, buf, BUFFER_SIZE);
	}
	return (buffer);
}

char	*ft_get_next_line(int fd)
{
	static char	*buffer;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_get_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	res = ft_getres(buffer);
	buffer = ft_move_to_nl(buffer);
	return (res);
}
