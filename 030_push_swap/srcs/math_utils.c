/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 13:27:52 by majacqua          #+#    #+#             */
/*   Updated: 2021/12/06 11:49:51 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	ft_same_sign(int a, int b)
{
	if ((a < 0 && b < 0) || (a > 0 && b > 0))
		return (1);
	return (0);
}
