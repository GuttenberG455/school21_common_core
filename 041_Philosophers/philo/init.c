/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:59:07 by majacqua          #+#    #+#             */
/*   Updated: 2022/01/28 18:19:53 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

ште 

int	init_philos(t_env *env)
{
	int i;

	i = env->philo_count;
	while (i > 0)
	{
		i--;
		env->philos[i].id = i; 
		env->philos[i].eat_count = 0;
		env->philos[i].last_time_eat = 0;
		env->philos[i].left_fork = i;
		env->philos[i].right_fork = (i + 1) % env->philo_count;
	}
	return (0);
}

int	init_env(t_env *env, char **argv)
{
	env->philo_count = ft_atoi(argv[1]);
	env->time_death = ft_atoi(argv[2]);
	env->time_eat = ft_atoi(argv[3]);
	env->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
	{
		env->num_eat = ft_atoi(argv[5]);
		if (env->num_eat <= 0)
			return (1);
	}
	else
		env->num_eat = -1;
	env->death = 0;
	if ((env->philo_count <= 0) || (env->philo_count > 322) || (env->time_death < 0) ||
			(env->time_eat < 0) || (env->time_sleep < 0))
		return (1);
	init_philos(env);
	return (0);
}