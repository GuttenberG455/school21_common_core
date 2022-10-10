/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:14:12 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/10/10 20:40:14 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *b, size_t n)
{
	size_t					i;
	unsigned char			*ret;

	ret = (unsigned char *) b;
	i = 0;
	while (i < n)
	{
		*ret = 0;
		++i;
		++ret;
	}
	return (ret - i);
}
