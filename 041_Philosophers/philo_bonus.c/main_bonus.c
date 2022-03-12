/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:12:45 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/12 17:19:56 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo_bonus.h"

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
	if (env.num_eat == 0)
		return (0);
	if (launch(&env))
		ft_close("Bad launch\nMission failed\n");
	return (1);
}

/*
1. Доделать лаунч
2. переделать слип
3. переделать принт экшн
4. сделать мейк

10. Проверки
11. Нормы
12. Флаги
*/