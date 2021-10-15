/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:01:52 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/15 11:47:38 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

// int	main(void)
// {
// 	int		file;
// 	char	*str;
// 	file = open("testfile", O_RDONLY);
// 	if (file == -1)
// 	{
// 		close(file);
// 		printf("map error\n");
// 		return (1);
// 	}
// 	// str = get_next_line(file);
// 	// while (str)
// 	// {
// 	// 	printf("==%s", str);
// 	// 	free(str);
// 	// 	str = get_next_line(file);
// 	// }
// 	printf("==%s", get_next_line(file));
// 	printf("==%s", get_next_line(file));
// 	printf("==%s", get_next_line(file));
// 	printf("==%s", get_next_line(file));
// 	printf("==%s", get_next_line(file));
// 	close(file);
// }

void	readfile(char *file, int print) {
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (print)
			// printf("%s\n", line);
		free(line);
	}
	line = get_next_line(fd);
	if (line)
	{
		if (print)
			printf("%s\n", line);
		free(line);
	}
	close(fd);
}

int		main(void)
{
	int	ex = 0;
	readfile("baudelaire.txt", !ex);
	// readfile("Mr._Justice_Maxell_by_Edgar_Wallace.txt", !ex);
	return (1);
}
