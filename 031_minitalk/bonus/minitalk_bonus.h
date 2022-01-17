/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:45:26 by majacqua          #+#    #+#             */
/*   Updated: 2022/01/17 15:45:34 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_message
{
	char	text_msg[BUFFER_SIZE];
	int		top_byte;
	int		top_bit;
	int		buff_overflow;
	int		all_recieved;
}		t_message;

t_message	g_msg = {"", 0, 65536, 0, 0};

void	ft_close(char *err_msg);

#endif
