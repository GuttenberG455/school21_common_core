/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:37:17 by majacqua          #+#    #+#             */
/*   Updated: 2022/05/10 15:36:38 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_env env;
	
	validate_input(argc, argv);
	env.map = get_map(argv[1]);
	print_map(env.map);
	printf("End;");
	return (0);	
}
