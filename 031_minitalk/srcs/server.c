/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:13:08 by majacqua          #+#    #+#             */
/*   Updated: 2022/01/12 18:37:35 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include "../libft/libft.h"
#include <stdio.h>

void	print_pid(void)
{
	write(1, "Server PID: ", 12);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
}

void	bit_one(int sig, siginfo_t *info, void *context)
{
	return ;
}

void	bit_zero(int sig, siginfo_t *info, void *context)
{
	return ;
}

int	main(void)
{
	struct sigaction	sa_one;
	struct sigaction	sa_zero;

	sa_one.sa_sigaction = bit_one;
	sa_zero.sa_sigaction = bit_zero;
	sa_one.sa_flags = SIGINFO;
	sa_zero.sa_flags = SIGINFO;
	if (sigaction(SIGUSR1, &bit_one, NULL) != 0)
		ft_close("Signal error\n");
	if (sigaction(SIGUSR2, &bit_zero, NULL) != 0)
		ft_close("Signal error\n");
	print_pid();
	// while (1)
	// 	pause();
	return (0);
}
