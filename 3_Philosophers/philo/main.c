/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:39:25 by majacqua          #+#    #+#             */
/*   Updated: 2022/03/14 15:33:25 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_close(char *str_error)
{
	printf("%s\n", str_error);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc != 5 && argc != 6)
		ft_close("Error!\nWrong amount of arguments");
	if (init_env(&env, argv))
		ft_close("Error!\nWrong input");
	if (env.num_eat == 0)
		return (0);
	if (launch(&env))
		ft_close("Error!\nThreads Error");
	return (0);
}
