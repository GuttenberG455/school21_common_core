/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:09:16 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/07 20:31:44 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memcpy(void *destptr, const void *srcptr, size_t size)
{
	size_t	i;
	char	*dest;
	char	*src;

	if (!destptr && !srcptr)
		return (0);
	i = 0;
	src = (char *) srcptr;
	dest = (char *) destptr;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	return (destptr);
}
