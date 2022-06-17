/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:25:32 by majacqua          #+#    #+#             */
/*   Updated: 2022/06/17 13:41:09 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
#define ENV_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "../vector/vector.h"
# include "../const.h"
# include "../libftv2/libftv2.h"
# include "../error/error.h"

typedef struct s_img	t_img;

typedef struct s_map
{
	char	*no_path;	// пути на картинки стен
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor_color;// цвета пола и потолка
	int		ceiling_color;
	t_img	*no_img;	// картинки стен
	t_img	*so_img;
	t_img	*we_img;
	t_img	*ea_img;
	size_t	width;		// ширина и высота поля
	size_t	height;
	int		num_start_grid; // номер строки, с которой начинается поле
	char	**grid;		// поле
}	t_map;

typedef struct s_env
{
	void	*mlx;	// библиотека mlx
	void	*win;	// окно
	t_vect	player;	// игрок
	t_map	*map;	// карта
	float	size;	// шаг, между разрешением окна и шириной карты
}	t_env;

t_map	*init_map(void);
t_vect	create_player(t_map *map, t_env *env);
void	print_map(t_map *map); // DELETE
void	print_player(t_vect player); // DELETE
void	print_vector(t_vect vect, char *str); // DELETE
#endif