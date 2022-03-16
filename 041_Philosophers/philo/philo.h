/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:39:32 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/16 19:09:50 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

# define ST_FORK	"has taken a fork"
# define ST_EAT		"is eating"
# define ST_SLEEP	"is sleeping"
# define ST_THINK	"is thinking"
# define ST_DEAD	"died"

struct	s_env;

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				eat_count;
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
	pthread_mutex_t	print_check;
	pthread_mutex_t	meal_check;
	pthread_mutex_t	death_check;
	t_philo			philos[322];
}		t_env;

long long	ft_atoi(char *str);
long long	get_timestamp(void);
void		print_action(t_env *env, int id, char *action);
void		print_death(t_env *env, int id);

void		thread_sleep(long long time);
int			init_env(t_env *env, char **argv);
void		act_eat(t_philo *philo);
void		ft_close(char *str_error);

int			launch(t_env *env);
int			check_all_fed(t_env *env);
int			death_thr_check(t_env *env);
int			meal_thr_check(t_env *env);

#endif