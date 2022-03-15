/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:16:49 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/15 19:56:40 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	act_eat(t_philo *philo)
{
	t_env	*env;

	env = philo->env;
	sem_wait(env->forks);
	print_action(env, philo->id, ST_FORK);
	sem_wait(env->forks);
	print_action(env, philo->id, ST_FORK);
	sem_wait(env->meal_check);
	philo->eat_count++;
	philo->last_time_eat = get_timestamp();
	sem_post(env->meal_check);
	print_action(env, philo->id, ST_EAT);
	proc_sleep(env->time_eat);
	sem_post(env->forks);
	sem_post(env->forks);
}

void	*check_end(void *void_philo)
{
	t_philo	*philo;
	t_env	*env;

	philo = (t_philo *) void_philo;
	env = philo->env;
	while (1)
	{
		check_death(env, philo);
		usleep(1000);
		sem_wait(env->meal_check);
		if (env->num_eat != -1 && philo->eat_count >= env->num_eat)
		{
			sem_post(env->meal_check);
			sem_wait(env->printing);
			exit (1);
		}
		sem_post(env->meal_check);
	}
	return (NULL);
}

void	start_process(void *void_philo)
{
	t_philo	*philo;
	t_env	*env;

	philo = (t_philo *) void_philo;
	env = philo->env;
	philo->last_time_eat = get_timestamp();
	pthread_create(&(philo->death_thread), NULL, check_end, void_philo);
	if (philo->id % 2)
		usleep(10000);
	while (1)
	{
		act_eat(philo);
		if (death_sem_check(env))
			break ;
		print_action(env, philo->id, ST_SLEEP);
		proc_sleep(env->time_sleep);
		print_action(env, philo->id, ST_THINK);
		if (death_sem_check(env))
			break ;
	}
	pthread_join(philo->death_thread, NULL);
	if (death_sem_check(env))
		exit (1);
	exit (0);
}

void	exit_launch(t_env *env)
{
	int	i;
	int	ret;

	i = 0;
	while (i < env->philo_count)
	{
		waitpid(-1, &ret, 0);
		if (ret != 0)
		{
			i = 0;
			while (i < env->philo_count)
			{
				kill(env->philos[i].id, SIGTERM);
				i++;
			}
			break ;
		}
		i++;
	}
	destroy_sems(env);
}

int	launch(t_env *env)
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
	exit_launch(env);
	return (0);
}
