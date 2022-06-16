/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:22:38 by majacqua          #+#    #+#             */
/*   Updated: 2022/06/16 14:42:46 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
#define HOOKS_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "../env/env.h"
# include "../const.h"
# include "../error/error.h"
# include "../render/render.h"
# include "../vector/vector.h"

# define W_KEY		13
# define A_KEY		0
# define S_KEY		1
# define D_KEY		2
# define ESC		53
# define Q_KEY		12
# define E_KEY		14

# define LEFT_KEY	123
# define RIGHT_KEY	124
# define DOWN_KEY	125
# define UP_KEY		126

		
# define KEYHOLD	2
# define CLOSE_WIND	17

void	set_hooks(t_env *env);

#endif