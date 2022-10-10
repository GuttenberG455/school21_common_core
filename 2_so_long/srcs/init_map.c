/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:41:13 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/23 19:54:25 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/map.h"

void	get_dimensions(t_prog *prog, char **argv)
{
	int		fd;
	char	*line;

	prog->map.height = 0;
	prog->map.width = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_close("Error\nNo such file\n");
	while (get_next_line(fd, &line))
	{
		prog->map.width = ft_strlen(line);
		prog->map.height++;
		free(line);
	}
	prog->map.height++;
	free(line);
	close(fd);
}

void	get_map_grid(t_prog *prog, char *file_name)
{
	int	row;
	int	fd;

	prog->map.grid = malloc(sizeof(char *) * (prog->map.height + 1));
	if (!prog->map.grid)
		ft_close("Error\nNot enough space for map grid\n");
	prog->map.grid[prog->map.height] = 0;
	row = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_close("Error\nNo such file\n");
	while (get_next_line(fd, &prog->map.grid[row]))
		row++;
	close(fd);
}

void	check_map_status(int status)
{
	if (status == 10)
		ft_close("Error\nIncorrect map: No borders"); //очистить карты
	else if (status == 11)
		ft_close("Error\nIncorrect map: Wrong dimensions");
	else if (status == 20)
		ft_close("Error\nIncorrect map: No player");
	else if (status == 21)
		ft_close("Error\nIncorrect map: Two or more players");
	else if (status == 30)
		ft_close("Error\nIncorrect map: No exit");
	else if (status == 31)
		ft_close("Error\nIncorrect map: Two or more exits");
	else if (status == 4)
		ft_close("Error\nIncorrect map: No coins");
	else if (status == 5)
		ft_close("Error\nIncorrect map: Wrong characters");
	else
		return ;
}

int	check_map_grid(t_prog *prog)
{
	get_counts(&prog->map);
	get_map_status(&prog->map);
	check_map_status(prog->map.status);
	return (0);
}
