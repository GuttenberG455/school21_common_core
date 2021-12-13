/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:58:30 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/13 12:22:24 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_MAP_H
# define GET_MAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>



typedef struct s_map {
	int				height;
	int				width;
	int				status;
	unsigned int	player_count;
	unsigned int	exit_count;
	unsigned int	coins_count;
	char			**grid;
}	t_map;

int		get_grid(char *file, char **grid);

void	ft_putstr(char *str);
void	print_map(char **grid);

void	print_error(int status);

int		check_map(t_map *map);

int		create_map(char *map_src);
int		count_ch_in_grid(char **grid, int ch);
int		check_dimensions(t_map *map);
int		get_dimensions(char *file, t_map *map);
#endif 