/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:56:34 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/06 12:43:49 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_bzero(void *ptr, size_t size)
{
	size_t		i;
	char		*str;

	i = 0;
	str = (char *) ptr;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	str = &str[i];
}
