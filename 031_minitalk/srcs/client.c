/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:13:10 by majacqua          #+#    #+#             */
/*   Updated: 2022/01/12 14:13:38 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include "../libft/libft.h"

void	send_char(int pid, unsigned char ch)
{
	
}

void	send_message(int pid, char *text_message)
{
	while (*text_message)
	{
		send_char(pid, *text_message);
	}
}

void	msg_status(int sig)
{
	(void)sig;
	write(1, "Data has been received.\n", 25);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		ft_close("Wrong amount of arguments\nHint: ./client [PID] [message]");
	signal(SIGUSR1, msg_status);
	send_message(ft_atoi(argv[1]), argv[2]);
}
