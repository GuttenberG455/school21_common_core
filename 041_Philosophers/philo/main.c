/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:39:25 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/10 18:26:12 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_close(char *str_error)
{
	write(1, str_error, ft_strlen(str_error));
	exit(1);
}

int main(int argc, char **argv)
{
	t_env env;

	if (argc != 5 && argc != 6) 
		ft_close("Wrong amount of arguments\n");
	if (init_env(&env, argv))
		ft_close("Wrong input\n");
	printf("%d %d %d %d %d\n", env.philo_count, env.time_death, env.time_eat, env.time_sleep, env.num_eat);
	if (launch(&env))
		ft_close("Bad launch\nMission failed\n");
	return (1);
}