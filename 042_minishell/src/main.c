/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:31:36 by rusty             #+#    #+#             */
/*   Updated: 2022/02/23 12:37:03 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_shell(t_shell *shell, char **envp)
{
	char	*buf;

	ft_bzero(shell, sizeof(t_shell));
	shell->env = init_env(envp);
	buf = ft_itoa(ft_atoi(get_env_par(shell->env, "SHLVL")) + 1);
	set_env_par(shell->env, "SHLVL", buf);
	return (0);
}

void	execute_input(t_shell *shell, char *read)
{
	char	*str;

	str = ft_strdup(read);
	// check_input(str);
	str = cut_spaces(str);
	// printf("%s\n", str);

	str = put_global(shell->env, str);
	printf("%s\n", str);
	// ft_free_tmp();
}

t_heap	g_heap;

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	char	*read;

	(void)argc;
	(void)argv;
	g_heap.shell = (void *)&shell;
	g_heap.count = 0;
	if (init_shell(&shell, envp))
		return (1); // ?
	while (!shell.exit)
	{
		shell.cmds = 0;// ?bzero
		// signal(SIGQUIT, SIG_IGN);
		// signal(SIGINT, sig_int_empty);
		read = readline(PROMPT);
		if (!read)
			break ;
		// if (check_int_skip(&shell, read))
		// 	continue ;
		if (ft_strlen(read) > 0)
			add_history(read);
		execute_input(&shell, read);
		free(read);
	}
	ft_free();
	return (shell.exit_status);
}
