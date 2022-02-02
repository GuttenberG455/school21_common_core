/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:57:42 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/02 18:55:23 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void act_eat(t_philo *philo)
{
	t_env	*env;

	env = philo->env;
	pthread_mutex_lock(&(env->forks[philo->left_fork]));
	printf("%lld %d has taken a fork\n", timestamp(), philo->id);
	pthread_mutex_lock(&(env->forks[philo->right_fork]));
	printf("%lld %d has taken a fork\n", timestamp(), philo->id);
	pthread_mutex_lock(&(env->meal_check));
	printf("%lld %d is eating\n", timestamp(), philo->id);
	philo->last_time_eat = timestamp();
	pthread_mutex_unlock(&(env->meal_check));
	thread_sleep(env, env->time_eat);
	philo->x_ate++;
	pthread_mutex_lock(&(env->forks[philo->left_fork]));
	pthread_mutex_lock(&(env->forks[philo->right_fork]));
}


void *start_thread(void *void_philo)
{
	int		i;
	t_env	*env;
	t_philo	*philo;

	i = 0;
	philo = void_philo;
	env = philo->env;
	if (philo->id % 2)
		usleep(10000);
	while (!(env->death))
	{
		act_eat(philo);
		if (env->all_fed)
			break;
		printf("%lld %d is sleeping\n", timestamp(), philo->id);
		thread_sleep(env, env->time_sleep);
		printf("%lld %d is thinking\n", timestamp(), philo->id);
		i++;
	}
	return (0);
}


void check_death(t_env *env, t_philo *philo)
{
	int		i;

	while (env->all_fed)
	{
		i = 0;
		while (env->philo_count && env->death)
		{
			pthread_mutex_lock(&(env->meal_check)); // втф?
			if (philo[i].last_time_eat - timestamp() > env->time_death)
			{
				printf("%lld %d died\n", timestamp(), i);
				env->death = 1;
			}
			if (env->death)
				break;
			i = 0;
			while (env->num_eat && i < env->philo_count && philo[i].x_ate >= env->num_eat)
				i++;
			if (i == env->philo_count)
				env->num_eat = 1;
		}
	}
}

void exit_launch(t_env *env, t_philo *philo)
{
	int i;

	i = 0;
	while (i < env->philo_count)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < env->philo_count)	
	{
		pthread_mutex_destroy(&(env->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(env->printing));
}

int launch(t_env *env)
{
	int		i;
	t_philo	*philo;

	i = 0;
	env->num_eat = timestamp();
	philo = env->philos;
	while (i < env->philo_count)
	{
		if (pthread_create(&(philo[i].thread), 0, start_thread, &(philo[i])))
			return (1);
		philo[i].last_time_eat = timestamp();
		i++;
	}
	check_death(env, env->philos);
	exit_launch(env, philo);
	return (0);
}