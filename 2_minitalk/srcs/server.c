/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:13:08 by majacqua          #+#    #+#             */
/*   Updated: 2022/01/17 17:10:56 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include "../libft/libft.h"

void	print_pid(void)
{
	write(1, "Server PID: ", 12);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
}

void	bit_one(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	(void)info;
	if (!g_msg.top_bit)
	{
		g_msg.top_bit = 64;
		g_msg.top_byte++;
	}
	g_msg.text_msg[g_msg.top_byte] += g_msg.top_bit;
	g_msg.top_bit >>= 1;
	if (g_msg.top_byte == BUFFER_SIZE - 2 && !g_msg.top_bit)
		g_msg.buff_overflow = 1;
}

void	bit_zero(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)info;
	(void)context;
	if (!g_msg.top_bit)
	{
		g_msg.top_bit = 64;
		g_msg.top_byte++;
	}
	g_msg.top_bit >>= 1;
	if (g_msg.top_byte == BUFFER_SIZE - 2 && !g_msg.top_bit)
		g_msg.buff_overflow = 1;
	else if (!g_msg.text_msg[g_msg.top_byte] && !g_msg.top_bit)
		g_msg.all_recieved = 1;
}

int	main_handler(void)
{
	while (1)
	{
		pause();
		if (g_msg.all_recieved || g_msg.buff_overflow)
		{
			write(1, g_msg.text_msg, ft_strlen(g_msg.text_msg));
			ft_bzero(g_msg.text_msg, BUFFER_SIZE);
			g_msg.top_byte = 0;
			g_msg.top_bit = 64;
			if (g_msg.all_recieved)
				write(1, "\n", 1);
			g_msg.all_recieved = 0;
			g_msg.buff_overflow = 0;
		}
	}
	return (1);
}

int	main(void)
{
	struct sigaction	sa_one;
	struct sigaction	sa_zero;

	sa_one.sa_sigaction = bit_one;
	sa_one.sa_flags = SA_SIGINFO;
	sa_zero.sa_sigaction = bit_zero;
	sa_zero.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_one, NULL) != 0)
		ft_close("Error\nBad sigaction\n");
	if (sigaction(SIGUSR2, &sa_zero, NULL) != 0)
		ft_close("Error\nBad sigaction\n");
	print_pid();
	ft_bzero(g_msg.text_msg, BUFFER_SIZE);
	main_handler();
}
