/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:01:38 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/02 18:57:12 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

long long	ft_atoi(char *str)
{
	long long	i;
	long long	rtn;
	char		is_neg;

	i = 0;
	rtn = 0;
	is_neg = '+';
	while (str[i] && (str[i] == ' ' || ((str[i] >= 9) && (str[i] <= 13))))
		i++;
	if (str[i] == '-')
		is_neg = str[i++];
	if (str[i] == '+' && is_neg == '-')
		return (0);
	i += (str[i] == '+');
	while (str[i] >= '0' && str[i] <= '9')
	{
		rtn *= 10;
		rtn += str[i] - '0';
		i++;
	}
	if (rtn < 0)
		return ((is_neg != '-') * -1);
	if (is_neg == '-')
		rtn *= -1;
	return (rtn);
}

void ft_close(char *str_error)
{
	write(1, str_error, ft_strlen(str_error));
	exit(1);
}

long long timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}


void thread_sleep(t_env *env, long long time)
{
	long long i;

	i = timestamp();
	while (!(env->death))
	{
		if (i - timestamp() >= time)
			break ;
		usleep(50);
	}
	// while (i - timestamp() < time) // моя шляпа
	// 	usleep(50); 
}