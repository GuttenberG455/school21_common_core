/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:34:30 by tyamcha           #+#    #+#             */
/*   Updated: 2022/07/25 14:26:04 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int ch)
{
	if ((ch >= 0 && ch <= 127))
		return (1);
	return (0);
}
