/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:46:20 by majacqua          #+#    #+#             */
/*   Updated: 2022/01/17 17:04:47 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include "../libft/libft.h"

void	msg_status(int sig)
{
	(void) sig;
	write(1, "Message delivered.\n", 19);
}

void	send_char(int pid, unsigned char ch)
{
	int		counter;

	counter = 65536;
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
		usleep(282);
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
	signal(SIGUSR1, msg_status);
	send_message(ft_atoi(argv[1]), argv[2]);
	return (0);
}
