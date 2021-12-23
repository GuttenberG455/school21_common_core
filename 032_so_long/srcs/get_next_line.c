/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:52:50 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/23 19:23:26 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/map.h"

static char	*get_stat(char *statstr)
{
	int		i;
	char	*line;

	i = 0;
	if (!statstr)
		return (0);
	while (statstr[i] != '\n' && statstr[i])
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		ft_close("Error\nStatic string creation failed");
	i = 0;
	while (statstr[i] != '\n' && statstr[i])
	{
		line[i] = statstr[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

static char	*save_stat(char *statstr)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!statstr)
		return (0);
	while (statstr[i] != '\n' && statstr[i])
		i++;
	if (statstr[i] == 0)
	{
		free(statstr);
		return (0);
	}
	line = malloc((ft_strlen(statstr) - i + 1) * sizeof(char));
	if (!line)
		ft_close("Error\nStatic string creation failed");
	i++;
	while (statstr[i])
		line[j++] = statstr[i++];
	line[j] = 0;
	free(statstr);
	return (line);
}

char	*create_temp_str(int fd, char **line, int size)
{
	char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (0);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	return (str);
}

int	get_next_line(int fd, char **line)
{
	static char	*statstr = 0;
	char		*tmp;
	int			byte_count;

	tmp = create_temp_str(fd, line, BUFFER_SIZE);
	if (!tmp)
		ft_close("Error\nStatic string creation failed");
	byte_count = 1;
	while (!ft_islinebreak(statstr) && byte_count)
	{
		byte_count = read(fd, tmp, BUFFER_SIZE);
		if (byte_count == -1)
		{
			free(tmp);
			return (-1);
		}
		tmp[byte_count] = 0;
		statstr = ft_strjoin_gnl(statstr, tmp);
	}
	free(tmp);
	*line = get_stat(statstr);
	statstr = save_stat(statstr);
	if (byte_count == 0)
		return (0);
	return (1);
}
