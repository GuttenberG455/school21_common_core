/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:52:02 by majacqua          #+#    #+#             */
/*   Updated: 2022/06/03 15:58:27 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hooks.h"

int	endgame(t_env *env)
{
	free_img(env->mlx, env->map->no_img);
	free_img(env->mlx, env->map->so_img);
	free_img(env->mlx, env->map->we_img);
	free_img(env->mlx, env->map->ea_img);
	mlx_destroy_window(env->mlx, env->win);
	// ft_free();
	exit (EXIT_SUCCESS);
}

t_vect	make_step(t_env *env, int dir, int ang)
{
	t_vect	res;

	res.dist = env->size * STEP_SIZE * dir;
	res.angle = env->player.angle;
	if (ang < 0)
		res.angle -= PI / 2;
	res.x = res.dist * cosf(res.angle);
	res.y = res.dist * sinf(res.angle);
	res = vect_add(env->player, res);
	if (env->map->grid[(int)(res.y / env->size)][(int)(env->player.x \
		/ env->size)] == '1' && \
		env->map->grid[(int)(env->player.y / env->size)][(int)(res.x \
		/ env->size)] == '1')
		return (env->player);
	if (env->map->grid[(int)(res.y / env->size)][(int)(res.x \
		/ env->size)] == '1')
		return (env->player);
	return (res);
}

int	key_press(int keycode, t_env *env)
{
	printf("Angle - [%f] Position - [%fx%f] \n", env->player.angle, env->player.x, env->player.y);
	if (keycode == W_KEY)
		env->player = make_step(env, -1, 1);
	if (keycode == S_KEY)
		env->player = make_step(env, 1, 1);
	if (keycode == A_KEY)
		env->player = make_step(env, -1, -1);
	if (keycode == D_KEY)
		env->player = make_step(env, 1, -1);
	if (keycode == Q_KEY)
		env->player.angle -= 2 * 0.01;
	if (keycode == E_KEY)
		env->player.angle += 2 * 0.01;
	if (keycode == ESC)
		endgame(env);
	if (env->player.angle > PI * 2)
			env->player.angle -= PI * 2;
	if (env->player.angle < 0)
			env->player.angle += PI * 2;
	render(env);
	return (0);
}

void	set_hooks(t_env *env)
{
	mlx_hook(env->win, KEYHOLD, 1L << 0, key_press, env);
	mlx_hook(env->win, CLOSE_WIND, 1L << 0, endgame, env);
}
