/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:13:10 by majacqua          #+#    #+#             */
/*   Updated: 2022/01/11 15:53:44 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	if (argc != 3)
		ft_close("Wrong amount of arguments\nHint: ./client [PID] [message]");
}
