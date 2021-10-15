/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:03:27 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/15 12:33:01 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*ft_savestat(char *str)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	new = malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
	if (!new)
		return (0);
	i++;
	while (str[i])
		new[j++] = str[i++];
	new[j] = 0;
	free(str);
	// printf("_%s_ - savestat\n", new);
	return (new);
}

char	*ft_getstat(char *str)
{
	char	*new;
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	new = malloc(sizeof(char) * i + 1);
	if (!new)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = str[i];
	new[i + 1] = 0;
	if (new[0] == 0)
	{
		free(new);
		return (0);
	}
	return (new);
}

char	*get_next_line(int fd)
{
	char		*temp;
	static char	*statstr = 0;
	int			byte_count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp)
		return (0);
	byte_count = 1;
	while (byte_count && !ft_islinebreak(statstr))
	{
		byte_count = read(fd, temp, BUFFER_SIZE);
		if (byte_count == -1)
		{
			free(temp);
			return (0);
		}
		temp[byte_count] = 0;
		printf("\n[%s]+[%s]\n", statstr, temp);
		statstr = ft_strjoin(statstr, temp);
		printf("statjoined = (%s)\n", statstr);
	}
	free(temp);
	temp = ft_getstat(statstr);
	statstr = ft_savestat(statstr);
	// printf("\nreturn - [%s] stat-(%s)\n", temp, statstr);
	return (temp);
}
