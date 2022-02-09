/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:57:42 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/09 19:21:48 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void act_eat(t_philo *philo)
{
	t_env	*env;

	env = philo->env;
	pthread_mutex_lock(&(env->forks[philo->left_fork]));
	print_action(env, philo->id, "has taken a fork");
	pthread_mutex_lock(&(env->forks[philo->right_fork]));
	print_action(env, philo->id, "has taken a fork");
	pthread_mutex_lock(&(env->meal_check));
	philo->eat_count++;
	print_action(env, philo->id, "is eating");
	philo->last_time_eat = timestamp();
	pthread_mutex_unlock(&(env->meal_check));
	// // thread_sleep(env, env->time_eat); // чекаем другое говно
	usleep(env->time_eat * 1000);
	pthread_mutex_unlock(&(env->forks[philo->left_fork]));
	pthread_mutex_unlock(&(env->forks[philo->right_fork]));
}


void *start_thread(void *void_philo)
{
	int		i;
	t_env	*env;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)void_philo;
	env = philo->env;
	if (philo->id % 2)
	{	
		usleep(10000);
	}
	while (!(env->end_death) && !(env->end_all_fed))
	{
		if (env->num_eat != -1 || (env->num_eat != -1 && philo->eat_count < env->num_eat))
			act_eat(philo);
		if (env->end_all_fed)
			break;
		print_action(env, philo->id, "is sleeping");
		// thread_sleep(env, env->time_sleep);
		usleep(env->time_sleep * 1000);
		print_action(env, philo->id, "is thinking");
		i++;
	}
	return (0);
}


void check_death(t_env *env, t_philo *philo)
{
	int		i;

	while (env->end_all_fed == 0)
	{
		i = 0;
		// while (i < env->philo_count && !env->end_death)
		// {
		// 	// pthread_mutex_lock(&(env->meal_check)); // втф?
		// 	// if (philo[i].last_time_eat - timestamp() > env->time_end_death)
		// 	// {
		// 	// 	printf("%lld %d died\n", timestamp(), i);
		// 	// 	env->end_death = 1;
		// 	// }
		// 	// pthread_mutex_unlock(&(env->meal_check)); // втф?
		// 	// i++;
		// 	// usleep(100);
		// }
		if (env->end_death)
			break;
		i = 0;
		while (env->num_eat != -1 && i < env->philo_count && philo[i].eat_count >= env->num_eat)
			i++;
		if (i == env->philo_count)
			env->end_all_fed = 1;
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
	env->start_time = timestamp();
	printf("Time start %lld\n", env->start_time);
	philo = env->philos;
	while (i < env->philo_count)
	{
		printf("Cre_%d_\n", i);
		if (pthread_create(&(philo[i].thread), 0, start_thread, &(philo[i])))
			return (1);
		philo[i].last_time_eat = timestamp();
		i++;
	}
	check_death(env, env->philos);
	exit_launch(env, philo);
	return (0);
} 

/*
1. Они не дохнут
2. Тайминги слетают
3. Посмотреть на слипы
4. Чекнуть дедлок
5. Проверить алгоритм
СДОХНИТЕ ТВАРИ
ВСЕ ФИЛОСОФЫ ДОЛЖНЫ УМЕРЕТЬ
10. Норма
11. Хуерма
12. Флаги
13. Бонусы

*/