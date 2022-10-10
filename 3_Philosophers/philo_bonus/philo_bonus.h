/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:09:52 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/16 14:24:13 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>

# define ST_FORK "has taken a fork"
# define ST_EAT "is eating"
# define ST_SLEEP "is sleeping"
# define ST_THINK "is thinking"
# define ST_DEAD "died"

struct	s_env;

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	long long		last_time_eat;
	struct s_env	*env;
	pthread_t		death_thread;
	pid_t			pid;
}		t_philo;

typedef struct s_env
{
	int				philo_count;
	int				time_death;
	int				time_eat;
	int				time_sleep;
	int				num_eat;
	int				end_death;
	long long		start_time;
	sem_t			*forks;
	sem_t			*printing;
	sem_t			*meal_check;
	sem_t			*dead_check;
	t_philo			philos[322];
}		t_env;

void		ft_close(char *str_error);

long long	ft_atoi(char *str);
long long	get_timestamp(void);
void		print_action(t_env *env, int id, char *action);
void		proc_sleep(long long time);
void		destroy_sems(t_env *env);
int			init_env(t_env *env, char **argv);
int			launch(t_env *env);

void		check_death(t_env *env, t_philo *philo);
int			death_sem_check(t_env *env);
int			meal_sem_check(t_env *env, t_philo *philo);

#endif