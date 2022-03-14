/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:01:38 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/14 13:01:44 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

long long	get_timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	thread_sleep(long long time)
{
	long long	i;

	i = get_timestamp();
	while (1)
	{
		if ((get_timestamp() - i) >= time)
			break ;
		usleep(50);
	}
}

void	print_action(t_env *env, int id, char *action)
{
	pthread_mutex_lock(&env->printing);
	if (!env->end_death && !env->end_all_fed)
	{
		printf("%lli", get_timestamp() - env->start_time);
		printf(" %d ", id + 1);
		printf("%s\n", action);
	}
	pthread_mutex_unlock(&env->printing);
}
