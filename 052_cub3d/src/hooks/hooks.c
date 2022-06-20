/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:52:02 by majacqua          #+#    #+#             */
/*   Updated: 2022/06/20 12:52:04 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hooks.h"

int	close_game(t_env *env)
{
	free_img(env->mlx, env->map->no_img);
	free_img(env->mlx, env->map->so_img);
	free_img(env->mlx, env->map->we_img);
	free_img(env->mlx, env->map->ea_img);
	mlx_destroy_window(env->mlx, env->win);
	ft_free();
	exit (EXIT_SUCCESS);
}

t_vect	make_step(t_env *env, int dir_x, int dir_y)
{
	t_vect	res;

	res.dist = env->size * STEP_SIZE * dir_x; // длина шага
	res.angle = env->player.angle; // угол не меняется
	if (dir_y < 0)
		res.angle -= PI / 2;
	res.x = res.dist * cosf(res.angle); // изменение по координате x
	res.y = res.dist * sinf(res.angle); // изменение по координате y
	res = vect_add(env->player, res); // складываем вектор игрока с вектором перемещения
	if ((env->map->grid[(int)(res.y / env->size)][(int)(env->player.x \
		/ env->size)] == '1' && \
		env->map->grid[(int)(env->player.y / env->size)][(int)(res.x \
		/ env->size)] == '1') ||
		(env->map->grid[(int)(res.y / env->size)][(int)(res.x \
		/ env->size)] == '1'))
		return (env->player); // Коллизия
	return (res);
}

int	key_press(int keycode, t_env *env)
{
	// printf("Angle - [%f] Position - [%fx%f] Dist= \n", env->player.angle, env->player.x, env->player.y);
	if (keycode == W_KEY || keycode == UP_KEY) // шаги
		env->player = make_step(env, -1, 1);
	if (keycode == S_KEY || keycode == DOWN_KEY)
		env->player = make_step(env, 1, 1);
	if (keycode == A_KEY)
		env->player = make_step(env, -1, -1);
	if (keycode == D_KEY)
		env->player = make_step(env, 1, -1);
	if (keycode == Q_KEY || keycode == LEFT_KEY) // повороты
		env->player.angle -= ROTATE_ANG;
	if (keycode == E_KEY || keycode == RIGHT_KEY)
		env->player.angle += ROTATE_ANG;
	if (keycode == ESC)
		close_game(env); // закрыть игру
	if (env->player.angle > PI * 2) // когда около 360 градусов (реализация поворота вокруг оси)
			env->player.angle -= PI * 2;
	if (env->player.angle < 0)
			env->player.angle += PI * 2;
	render(env); // Рендер после действия
	return (0);
}

void	set_hooks(t_env *env)
{
	mlx_hook(env->win, KEYHOLD, 1L << 0, key_press, env); // нажатие на клавишу
	mlx_hook(env->win, CLOSE_WIND, 1L << 0, close_game, env);	// закрыть окно
}
