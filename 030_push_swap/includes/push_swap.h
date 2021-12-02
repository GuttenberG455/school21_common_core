/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:46:13 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/02 15:46:04 by majacqua         ###   ########.fr       */
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

typedef struct s_env{
	t_lstack		**stack_a;
	t_lstack		**stack_b;
	int				looking;
	int				mid;
	int				max;
	int				flag;
	unsigned int	step_count;
}	t_env;

int			create_start_stack(t_env *env, int argc, char **argv);
t_lstack	*ft_create_list(int value);
int			is_sorted(t_lstack **stack);
int			is_number(char *str);
int			is_dublicate(t_lstack **stack);
int			get_value_by_order(t_lstack **stack, int ord);

void		tiny_sort(t_env *env);
void		sort_two(t_env *env, int stack_num);
void		sort_three_stack_a(t_env *env);
void		sort_three_stack_b(t_env *env);
void		merge_two_sorted_stacks(t_env *env);
void		sort_four_to_six(t_env *env);

void		large_sort(t_env *env);
void		large_first_push(t_env *env);
void		large_b_sort(t_env *env);
void		large_no_flag_push(t_env *env);
void		large_flag_push(t_env *env);
int			large_fast_sort_two(t_env *env, int flag);
int			large_fast_b_two_three(t_env *env);

void		ft_print_list(t_lstack **stack);
void		ft_print_env(t_env *env);
void		ft_push_list(t_lstack **stack, t_lstack *new);
t_lstack	*ft_last_lstack(t_lstack **stack);
size_t		ft_lstack_len(t_lstack **stack);

void		op_swap_one(t_lstack **stack);
void		op_push(t_lstack **stack1, t_lstack **stack2, int to_b, t_env *env);
void		op_rotate_one(t_lstack **stack);
void		op_reverse_rotate_one(t_lstack **stack);

void		oper_sa(t_env *env);
void		oper_sb(t_env *env);
void		oper_ss(t_env *env);
void		oper_pa(t_env *env);
void		oper_pb(t_env *env);
void		oper_ra(t_env *env);
void		oper_rb(t_env *env);
void		oper_rr(t_env *env);
void		oper_rra(t_env *env);
void		oper_rrb(t_env *env);
void		oper_rrr(t_env *env);
#endif