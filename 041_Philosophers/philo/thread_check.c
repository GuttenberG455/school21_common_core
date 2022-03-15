/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:30:38 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/15 14:32:55 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death_thr_check(t_env *env)
{
	pthread_mutex_lock(&env->death_check);
	if (env->end_death)
	{
		pthread_mutex_unlock(&env->death_check);
		return (1);
	}
	pthread_mutex_unlock(&env->death_check);
	return (0);
}

int	meal_thr_check(t_env *env)
{
	pthread_mutex_lock(&env->meal_check);
	if (env->end_all_fed)
	{
		pthread_mutex_unlock(&env->meal_check);
		return (1);
	}
	pthread_mutex_unlock(&env->meal_check);
	return (0);
}
