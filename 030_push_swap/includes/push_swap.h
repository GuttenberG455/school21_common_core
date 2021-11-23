/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:46:13 by majacqua          #+#    #+#             */
/*   Updated: 2021/11/23 19:56:30 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_lstack{
	int				value;
	int				order;
	int				flag;
	struct s_lstack	*prev;
	struct s_lstack	*next;
}	t_lstack;

int			create_start_stack(t_lstack **stack, int argc, char **argv);
t_lstack	*ft_create_list(int value);
void		ft_print_list(t_lstack **lst);
void		ft_push_list(t_lstack **lst, t_lstack *new);

int			op_swap_one(t_lstack **stack);
void		op_swap_two(t_lstack **stack1, t_lstack **stack2);
void		op_push(t_lstack **stack1, t_lstack **stack2);

#endif