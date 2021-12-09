/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:19:23 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/09 12:47:15 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

int	do_instruction(t_env *env, char *str)
{
	if (!ft_strncmp(str, "sa\n", 5))
		oper_sa(env);
	else if (!ft_strncmp(str, "sb\n", 5))
		oper_sb(env);
	else if (!ft_strncmp(str, "ss\n", 5))
		oper_ss(env);
	else if (!ft_strncmp(str, "pb\n", 5))
		oper_pb(env);
	else if (!ft_strncmp(str, "pa\n", 5))
		oper_pa(env);
	else if (!ft_strncmp(str, "ra\n", 5))
		oper_ra(env);
	else if (!ft_strncmp(str, "rb\n", 5))
		oper_rb(env);
	else if (!ft_strncmp(str, "rr\n", 5))
		oper_rr(env);
	else if (!ft_strncmp(str, "rra\n", 5))
		oper_rra(env);
	else if (!ft_strncmp(str, "rrb\n", 5))
		oper_rrb(env);
	else if (!ft_strncmp(str, "rrr\n", 5))
		oper_rrr(env);
	else
		return (1);
	return (0);
}

void	get_instructions(t_env *env)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
		{
			if (!is_sorted(env->stack_a) && !ft_lstack_len(env->stack_b))
				ft_putstr_fd("OK\n", 1);
			else
				ft_putstr_fd("KO\n", 1);
			break ;
		}
		if (do_instruction(env, line))
		{
			ft_putstr_fd("Error\n", 1);
			free(line);
			return ;
		}
		free(line);
	}
}

int	main(int argc, char **argv)
{	
	t_env		*env;
	t_lstack	*stack_a;
	t_lstack	*stack_b;

	env = malloc(sizeof(t_env));
	if (!env)
		return (1);
	env->stack_a = &stack_a;
	env->stack_b = &stack_b;
	env->step_count = 0;
	env->max = 0;
	env->mid = 0;
	env->min = 0;
	if (create_start_stack(env, argc, argv))
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	get_instructions(env);
	return (1);
}
