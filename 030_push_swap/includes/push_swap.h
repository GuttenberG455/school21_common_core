/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:46:13 by majacqua          #+#    #+#             */
/*   Updated: 2021/11/27 14:03:00 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_lstack{
	int				value;
	int				order;
	int				flag;
	struct s_lstack	*prev;
	struct s_lstack	*next;
}	t_lstack;

void		tiny_sort(t_lstack **stack1, t_lstack **stack2);

void		large_sort(t_lstack **stack1, t_lstack **stack2);

void		large_first_push(t_lstack **stack1, t_lstack **stack2);

int			create_start_stack(t_lstack **stack, int argc, char **argv);
int			is_sorted(t_lstack **stack);

t_lstack	*ft_create_list(int value);
void		ft_print_list(t_lstack **stack);
void		ft_push_list(t_lstack **stack, t_lstack *new);
t_lstack	*ft_last_lstack(t_lstack **stack);
size_t		ft_lstack_len(t_lstack **stack);

void		op_swap_one(t_lstack **stack);
void		op_swap_two(t_lstack **stack1, t_lstack **stack2);
void		op_push(t_lstack **stack1, t_lstack **stack2);
void		op_rotate_one(t_lstack **stack);
void		op_rotate_two(t_lstack **stack1, t_lstack **stack2);
void		op_reverse_rotate_one(t_lstack **stack);
void		op_reverse_rotate_two(t_lstack **stack1, t_lstack **stack2);
#endif