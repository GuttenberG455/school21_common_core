/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:46:13 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/06 15:13:27 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

# ifndef INT_MAX
#  define INT_MAX 2147483647 
# endif

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
	int				min;
	int				mid;
	int				max;
	unsigned int	step_count;
}	t_env;

int			push_swap(int argc, char **argv);

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

int			get_current_pos(t_lstack **stack, int num);
int			count_steps_to_top(t_lstack **stack, int num);
void		large_push_mid(t_env *env);
void		large_push_all_2b(t_env *env);
void		large_count_flags(t_env *env);
int			find_closest_big(t_lstack **stack, int num);
int			find_min_flag(t_lstack **stack);
void		large_push_min_flag(t_env *env);

void		ft_push_list(t_lstack **stack, t_lstack *new);
t_lstack	*ft_last_lstack(t_lstack **stack);
size_t		ft_lstack_len(t_lstack **stack);
int			get_properties(t_env *env);

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

int			ft_min(int a, int b);
int			ft_abs(int a);
int			ft_same_sign(int a, int b);

#endif