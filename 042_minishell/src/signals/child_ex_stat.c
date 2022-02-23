void	set_exit_because_of_child(int stat, t_cmd *child, t_shell *shell)
{
	if (!WIFEXITED(stat))
	{	
		if (WIFSIGNALED(stat))
		{
			env_set("?", ft_itoa(WTERMSIG(stat) + 128), shell->env);
		}
		else
		{	
			env_set("?", ft_itoa(WEXITSTATUS(stat)), shell->env);
		}	
	}
	env_set("_", child->cmd, shell->env);
}