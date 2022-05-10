/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:25:32 by majacqua          #+#    #+#             */
/*   Updated: 2022/05/10 13:40:18 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
#define ENV_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "../const.h"
# include "../libftv2/libftv2.h"

typedef struct s_img	t_img;

typedef struct s_map
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor_color;
	int		ceiling_color;
	t_img	*no_img;
	t_img	*so_img;
	t_img	*we_img;
	t_img	*ea_img;
	size_t	width;
	size_t	height;
	char	**grid;
}	t_map;

typedef struct s_env
{
	void	*mlx;
	void	*win;
	t_map	*map;
}	t_env;

t_map	*init_map(void);
void	print_map(t_map *map); // DELETE

#endif