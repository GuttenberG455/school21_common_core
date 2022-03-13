/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:57:42 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/13 15:28:51 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	act_eat(t_philo *philo)
{
	t_env	*env;

	env = philo->env;
	pthread_mutex_lock(&env->forks[philo->left_fork]);
	print_action(env, philo->id, ST_FORK);
	pthread_mutex_lock(&env->forks[philo->right_fork]);
	print_action(env, philo->id, ST_FORK);
	pthread_mutex_lock(&env->meal_check);
	philo->eat_count++;
	philo->last_time_eat = get_timestamp();
	print_action(env, philo->id, ST_EAT);
	pthread_mutex_unlock(&env->meal_check);
	thread_sleep(env, env->time_eat);
	pthread_mutex_unlock(&env->forks[philo->right_fork]);
	pthread_mutex_unlock(&env->forks[philo->left_fork]);
}

void	check_death(t_env *env, t_philo *philo)
{
	int		i;

	while (!env->end_all_fed)
	{
		i = -1;
		while (++i < env->philo_count && !env->end_death)
		{
			pthread_mutex_lock(&env->meal_check);
			if (get_timestamp() - philo[i].last_time_eat > env->time_death)
			{
				print_action(env, philo->id, ST_DEAD);
				env->end_death = 1;
			}
			pthread_mutex_unlock(&env->meal_check);
			usleep(100);
		}
		if (env->end_death)
			break ;
		i = 0;
		while (env->num_eat != -1 && i < env->philo_count
			&& philo[i].eat_count >= env->num_eat)
			i++;
		if (i == env->philo_count)
			env->end_all_fed = 1;
	}
}

void	*start_thread(void *void_philo)
{
	int		i;
	t_env	*env;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *) void_philo;
	env = philo->env;
	if (philo->id % 2)
		usleep(10000);
	while (!(env->end_death))
	{
		act_eat(philo);
		if (env->end_all_fed)
			break ;
		print_action(env, philo->id, ST_SLEEP);
		thread_sleep(env, env->time_sleep);
		print_action(env, philo->id, ST_THINK);
		i++;
	}
	return (0);
}

void	exit_launch(t_env *env, t_philo *philo)
{
	int	i;

	i = 0;
	while (env->philo_count != 1 && i < env->philo_count)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < env->philo_count)
	{
		pthread_mutex_destroy(&env->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&env->printing);
	pthread_mutex_destroy(&env->meal_check);
}

int	launch(t_env *env)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = env->philos;
	env->start_time = get_timestamp();
	while (i < env->philo_count)
	{
		if (pthread_create(&philo[i].thread, 0, start_thread, &philo[i]))
			return (1);
		philo[i].last_time_eat = get_timestamp();
		i++;
	}
	check_death(env, env->philos);
	exit_launch(env, philo);
	return (0);
}
