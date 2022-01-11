/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:13:08 by majacqua          #+#    #+#             */
/*   Updated: 2022/01/11 15:52:54 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include "../libft/libft.h"

void	print_pid(void)
{
	char	*pid_str;

	pid_str = ft_itoa(getpid());
	write(1, "Server PID: ", 12);
	write(1, pid_str, ft_strlen(pid_str));
	write(1, "\n", 1);
	free(pid_str);
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
	struct sigaction	s_sigaction;

	print_pid();
	if (sigaction(SIGUSR1, &bit_one, NULL) != 0)
		ft_close("Signal error\n");
	if (sigaction(SIGUSR2, &bit_zero, NULL) != 0)
		ft_close("Signal error\n");
}
