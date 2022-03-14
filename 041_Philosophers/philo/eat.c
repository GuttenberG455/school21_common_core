/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:11:21 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/14 19:11:57 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_forks(t_philo *philo)
{
	t_env	*env;

	env = philo->env;
	if (philo->id % 2)
	{
		pthread_mutex_lock(&env->forks[philo->left_fork]);
		print_action(env, philo->id, ST_FORK);
		pthread_mutex_lock(&env->forks[philo->right_fork]);
		print_action(env, philo->id, ST_FORK);
	}
	else
	{
		pthread_mutex_lock(&env->forks[philo->right_fork]);
		print_action(env, philo->id, ST_FORK);
		if (env->philo_count == 1)
		{
			pthread_mutex_unlock(&env->forks[philo->left_fork]);
			thread_sleep(env->time_death);
			print_action(env, philo->id, ST_DEAD);
			env->end_death = 1;
			return ;
		}
		pthread_mutex_lock(&env->forks[philo->left_fork]);
		print_action(env, philo->id, ST_FORK);
	}
}

void	act_eat(t_philo *philo)
{
	t_env	*env;

	env = philo->env;
	lock_forks(philo);
	pthread_mutex_lock(&env->meal_check);
	philo->eat_count++;
	philo->last_time_eat = get_timestamp();
	print_action(env, philo->id, ST_EAT);
	pthread_mutex_unlock(&env->meal_check);
	thread_sleep(env->time_eat);
	pthread_mutex_unlock(&env->forks[philo->right_fork]);
	pthread_mutex_unlock(&env->forks[philo->left_fork]);
}
