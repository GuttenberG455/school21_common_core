/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:13:10 by majacqua          #+#    #+#             */
/*   Updated: 2022/01/17 17:10:15 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include "../libft/libft.h"

void	send_char(int pid, unsigned char ch)
{
	int		counter;

	counter = 64;
	while (counter)
	{
		if (ch & counter)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_close("Error\nWrong PID\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_close("Error\nWrong PID\n");
		}
		counter >>= 1;
		usleep(322);
	}
}

void	send_message(int pid, char *text_msg)
{
	while (*text_msg)
	{
		send_char(pid, *text_msg);
		text_msg++;
	}
	send_char(pid, *text_msg);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		ft_close("Error\nIncorrect input\nHint: ./client [PID] [message]");
	send_message(ft_atoi(argv[1]), argv[2]);
	return (0);
}
