/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:03:20 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/04 13:11:02 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int ch)
{
	if (ch >= 48 && ch <= 57)
		return (1);
	else
		return (0);
}
