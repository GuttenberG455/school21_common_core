#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>

#define STDIN	0
#define STDOUT	1
#define STDERR	2

#define TYPE_END	3
#define TYPE_PIPE	4
#define TYPE_BREAK	5

typedef	struct	s_cmd
{
	char			**argv;
	int				size;
	int				type;
	int				fd[2];
	struct s_cmd	*prev;
	struct s_cmd	*next;
}	t_cmd;

// Utils

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char *new;
	int i;

	if (!str)
		return (0);
	new = malloc(ft_strlen(str) + 1);
	if (!new)
		return (0);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

// Errors

void exit_fatal(void)
{
	write(STDERR, "error: fatal\n", ft_strlen("error: fatal\n"));
	exit(1);
}

void exit_bad_args1(void)
{
	write(STDERR, "error: cd: bad arguments\n", ft_strlen("error: cd: bad arguments\n"));
	exit(1);	
}

int exit_bad_args2(char *str)
{
	write(STDERR, "error: cd: cannot change directory to ", ft_strlen("error: cd: cannot change directory to "));
	write(STDERR, str, ft_strlen(str));
	write(STDERR, "\n", 1);
	return (1);
}

int exit_execve(char *str)
{
	write(STDERR, "error: cannot execute ", ft_strlen("error: cannot execute "));
	write(STDERR, str, ft_strlen(str));
	write(STDERR, "\n", 1);
	exit(1);
}

// Parser

void	lst_add_back(t_cmd **start, t_cmd *new)
{
	t_cmd *tmp;

	if (!(*start))
		*start = new;
	else
	{
		tmp = *start;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

int	size_argv(char **argv)
{
	int i = 0;
	while (argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0)
		i++;
	return (i);
}

int	parse_type(char *argv)
{
	if (!argv)
		return (TYPE_END);
	if (strcmp(argv, "|") == 0)
		return (TYPE_PIPE);
	if (strcmp(argv, ";") == 0)
		return (TYPE_BREAK);
	return (0);
}

int	parse_argv(t_cmd **start, char **argv)
{
	int size = size_argv(argv);
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		exit_fatal();
	new->argv = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new->argv)
		exit_fatal();
	new->size = size;
	new->next = 0;
	new->prev = 0;
	new->argv[size] = 0;
	while (--size >= 0)
		new->argv[size] = ft_strdup(argv[size]);
	new->type = parse_type(argv[new->size]);
	lst_add_back(start, new);
	return(new->size);
}

// Exec

void	exec_one(t_cmd *cmd, char **envp)
{
	pid_t	pid;
	int		status;
	int		pipe_open = 0;

	if (cmd->type == TYPE_PIPE || (cmd->prev && cmd->prev->type == TYPE_PIPE))
	{
		pipe_open = 1;
		if (pipe(cmd->fd))
			exit_fatal();
	}
	pid = fork();
	if (pid < 0)
		exit_fatal();
	else if (pid == 0)
	{
		if (cmd->type == TYPE_PIPE && dup2(cmd->fd[STDOUT], STDOUT) < 0)
			exit_fatal();
		if (cmd->prev && cmd->prev->type == TYPE_PIPE && dup2(cmd->fd[STDIN], STDIN) < 0)
			exit_fatal();
		if ((execve(cmd->argv[0], cmd->argv, envp)) < 0)
			exit_execve(cmd->argv[0]);
		exit (0);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (pipe_open)
		{
			close(cmd->fd[STDOUT]);
			if (cmd->next || cmd->next->type == TYPE_BREAK)
				close(cmd->fd[STDIN]);
		}
		if (cmd->prev && cmd->prev->type == TYPE_PIPE)
			close(cmd->prev->fd[STDIN]);
	}
}

void	exec_cmds(t_cmd *start, char **envp)
{
	t_cmd	*tmp;

	tmp = start;
	while (tmp)
	{
		if (strcmp(tmp->argv[0], "cd") == 0)
		{
			if (tmp->size < 2)
				exit_bad_args1();
			else if (chdir(tmp->argv[1]))
				exit_bad_args2(tmp->argv[1]);
		}
		else
			exec_one(tmp, envp);
		tmp = tmp->next;
	}
}

// Main

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*cmd = 0;
	t_cmd	*tmp;
	int i;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			if (strcmp(argv[i], ";") == 0)
			{
				i++;
				continue ;
			}
			i += parse_argv(&cmd, &argv[i]);
			if (!argv[i])
    	        break;
    	    else
    	        i++;
		}
		tmp = cmd;
		int c = 0;
		while (tmp)
		{
			i = 0;
			while (i < tmp->size)
			{
				printf("_%d_Com - [%s]\n", c, tmp->argv[i]);
				i++;
			}
			c++;
			tmp = tmp->next;
		}
		if (cmd)
			exec_cmds(cmd, envp);
	}
	return (0);
}