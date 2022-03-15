/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_check_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:10:16 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/15 19:55:53 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	death_sem_check(t_env *env)
{
	sem_wait(env->dead_check);
	if (env->end_death)
	{
		sem_post(env->dead_check);
		return (1);
	}
	sem_post(env->dead_check);
	return (0);
}

void	check_death(t_env *env, t_philo *philo)
{
	sem_wait(env->meal_check);
	if (get_timestamp() - philo->last_time_eat > env->time_death)
	{
		print_action(env, philo->id, ST_DEAD);
		sem_wait(env->dead_check);
		env->end_death = 1;
		sem_post(env->dead_check);
		sem_wait(env->printing);
		sem_post(env->meal_check);
		exit (1);
	}
	sem_post(env->meal_check);
}
