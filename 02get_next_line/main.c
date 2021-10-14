/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:01:52 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/14 17:40:49 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		file;
	char	*str;
	file = open("testfile", O_RDONLY);
	if (file == -1)
	{
		close(file);
		printf("map error\n");
		return (1);
	}
	// str = get_next_line(file);
	// while (str)
	// {
	// 	printf("==%s", str);
	// 	free(str);
	// 	str = get_next_line(file);
	// }
	printf("==%s", get_next_line(file));
	printf("==%s", get_next_line(file));
	printf("==%s", get_next_line(file));
	printf("==%s", get_next_line(file));
	printf("==%s", get_next_line(file));
	close(file);
}
