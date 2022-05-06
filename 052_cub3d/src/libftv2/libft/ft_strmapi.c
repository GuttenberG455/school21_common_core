/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubeetroo <ubeetroo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:26:14 by ubeetroo          #+#    #+#             */
/*   Updated: 2021/10/12 17:06:37 by ubeetroo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*ret;
	unsigned int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	ret = ft_strdup(s);
	if (ret == NULL)
		return (NULL);
	while (ret[i])
	{
		ret[i] = (*f)(i, s[i]);
		++i;
	}
	return (ret);
}
