/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:03:27 by majacqua          #+#    #+#             */
/*   Updated: 2021/11/18 11:12:28 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_grid.h"
#include "get_map.h"

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
	new = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!new)
		return (0);
	i++;
	while (str[i])
		new[j++] = str[i++];
	new[j] = 0;
	free(str);
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
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = 0;
	if (new[0] == 0)
	{
		free(new);
		return (0);
	}
	return (new);
}

char	*create_temp_str(int fd, int size)
{
	char	*str;

	if (fd < 0 || size <= 0)
		return (0);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (0);
	return (str);
}

int	get_next_line(int fd, char **map)
{
	char		*temp;
	static char	*statstr = 0;
	int			byte_count;

	temp = create_temp_str(fd, BUFFER_SIZE);
	if (temp == 0)
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
		statstr = ft_strjoin(statstr, temp);
	}
	free(temp);
	*map = ft_getstat(statstr);
	statstr = ft_savestat(statstr);
	if (byte_count == 0)
		return (0);
	return (1);
}

int	get_grid(char *file, char **grid)
{
	int		fd;
	int		reader;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	reader = 1;
	while (reader)
	{
		reader = get_next_line(fd, grid);
		grid++;
		if (!reader)
			break ;
	}
	*grid = 0;
	close(fd);
	return (0);
}
