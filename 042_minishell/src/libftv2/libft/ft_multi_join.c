/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:46:17 by rusty             #+#    #+#             */
/*   Updated: 2022/02/23 13:41:39 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*muljoin(char *str, va_list *args)
{
	char	*to_join;

	to_join = va_arg(*args, char *);
	while (to_join)
	{
		str = ft_strjoin(str, to_join);
		to_join = va_arg(*args, char *);
		ft_printf("_%p_\n", to_join);
	}
	return (str);
}

char	*ft_multi_join(const char *str, ...)
{
	va_list	args;
	char	*ret;
	char	*to_work;

	to_work = ft_strdup(str);
	va_start(args, str);
	ret = muljoin(to_work, &args);
	va_end(args);
	return (ret);
}
