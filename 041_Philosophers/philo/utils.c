/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 20:01:38 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/09 17:44:35 by majacqua         ###   ########.fr       */
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

long long timestamp(void) // возвращает кол-во миллисекунд со времен начала
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	// printf("TS %ld %d\n", tv.tv_sec, tv.tv_usec);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void print_action(t_env *env, int id, char *action)
{
	pthread_mutex_lock(&env->printing);
	printf("%lli", timestamp() - env->start_time);
	printf(" %d ", id + 1);
	printf("%s\n", action);
	pthread_mutex_unlock(&env->printing);
}