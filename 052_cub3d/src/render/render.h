/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:54:34 by majacqua          #+#    #+#             */
/*   Updated: 2022/05/11 16:50:41 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
#define RENDER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "../const.h"
# include "../env/env.h"
# include "../vector/vector.h"

# include "../libftv2/libftv2.h"
# include "../minilibx/mlx.h"

typedef struct s_img	t_img;

struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
	int		width;
	int		height;
};

void render(t_env *env);
t_img	*new_img(void *mlx);
t_img	*new_img_xpm(void *mlx, char *path);
t_vect *raycasting(t_env *env);

#endif