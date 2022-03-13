/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:27:01 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/13 15:26:34 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_sems(t_env *env)
{
	sem_unlink("philo_forks");
	sem_unlink("philo_printing");
	sem_unlink("philo_meal_check");
	env->forks = sem_open("philo_forks", O_CREAT, S_IRWXU, env->philo_count);
	env->printing = sem_open("philo_printing", O_CREAT, S_IRWXU, 1);
	env->meal_check = sem_open("philo_meal_check", O_CREAT, S_IRWXU, 1);
	if (env->forks <= 0 || env->printing <= 0 || env->meal_check <= 0)
		return (1);
	return (0);
}

int	init_philos(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->philo_count)
	{
		env->philos[i].id = i;
		env->philos[i].env = env;
		env->philos[i].eat_count = 0;
		env->philos[i].last_time_eat = 0;
		i++;
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
		if ((env->num_eat <= 0) && (argv[5][0] != '0'))
			return (1);
	}
	else
		env->num_eat = -1;
	env->end_death = 0;
	env->end_all_fed = 0;
	if (env->philo_count <= 0 || env->philo_count > 322 || env->time_death < 0
		|| env->time_eat < 0 || env->time_sleep < 0)
		return (1);
	init_philos(env);
	if (init_sems(env))
		return (1);
	return (0);
}
