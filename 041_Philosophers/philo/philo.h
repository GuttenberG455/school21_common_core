/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:39:32 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/09 18:50:07 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

struct s_env;

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int 			eat_count;
	long long		last_time_eat;
	struct s_env	*env;
	pthread_t		thread;
}		t_philo;

typedef struct s_env
{
	int				philo_count;
	int				time_death;
	int				time_eat;
	int				time_sleep;
	int				num_eat;
	int				end_death;
	int				end_all_fed;
	long long		start_time;
	pthread_mutex_t	forks[322];
	pthread_mutex_t	printing;
	pthread_mutex_t	meal_check;
	t_philo			philos[322];
}		t_env;

void		ft_close(char *str_error);
int			ft_strlen(char *str);
long long	ft_atoi(char *str);
long long 	timestamp(void);
void		print_action(t_env *env, int id, char *action);
void		thread_sleep(t_env *env, long long time);

int			init_env(t_env *env, char **argv);

int			launch(t_env *env);

#endif