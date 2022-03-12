/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:16:49 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/12 17:15:59 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	act_eat(t_philo *philo)
{
	t_env	*env;

	env = philo->env;
	sem_wait(env->forks);
	print_action(env, philo->id, "has taken a fork");
	sem_wait(env->forks);
	print_action(env, philo->id, "has taken a fork");
	sem_wait(env->meal_check);
	philo->eat_count++;
	philo->last_time_eat = get_timestamp();
	print_action(env, philo->id, "is eating");
	sem_post(env->meal_check);
	thread_sleep(env, env->time_eat);
	sem_post(env->forks);
	sem_post(env->forks);
}

void	check_death(void *void_philo)
{
	t_philo	*philo;
	t_env	*env;

	philo = (t_philo *) void_philo;
	env = philo->env;
	while (1)
	{
		sem_wait(env->meal_check);
		if (get_timestamp() - philo->last_time_eat > env->time_death)
		{
			print_action(env, philo->id, "died");
			env->end_death = 1;
			sem_wait(env->printing);
			exit (1);
		}
		sem_post(env->meal_check);
		if (env->end_death)
			break;
		usleep(1000);
		if (env->num_eat != -1 && philo->eat_count >= env->num_eat)
			break;
	}
}

void	start_process(void *void_philo)
{
	t_philo	*philo;
	t_env	*env;

	philo = (t_philo *) void_philo;
	env = philo->env;
	philo->last_time_eat = get_timestamp();
	pthread_create(&(philo->death_thread), NULL, check_death, void_philo);
	if (philo->id % 2)
		usleep(10000);
	while (!(env->end_death))
	{
		act_eat(philo);
		if (env->end_all_fed)
			break;
		print_action(env, philo->id, "is sleeping");
		thread_sleep(env, env->time_sleep);
		print_action(env, philo->id, "is thinking");
	}
	pthread_join(philo->death_thread, NULL);
	if (env->end_death)
		exit (1);
	exit (0);
}

int launch(t_env *env)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = env->philos;
	env->start_time = get_timestamp();
	
	while (i < env->philo_count)
	{
		philos[i].pid = fork();
		if (philos[i].pid < 0)
			return (1);
		if (philos[i].pid == 0)
			start_process(&philos[i]);
		usleep(100);
		i++;
	}
}