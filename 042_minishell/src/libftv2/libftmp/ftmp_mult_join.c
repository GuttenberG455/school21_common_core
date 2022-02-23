/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmp_mult_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:28:18 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/23 12:28:42 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmp.h"

char	*tmp_muljoin(char *str, va_list *args)
{
	char	*to_join;

	to_join = va_arg(*args, char *);
	while (to_join)
	{
		str = ftmp_strjoin(str, to_join);
		to_join = va_arg(*args, char *);
	}
	return (str);
}

char	*ftmp_multi_join(const char *str, ...)
{
	va_list	args;
	char	*ret;
	char	*to_work;

	to_work = ftmp_strdup(str);
	va_start(args, str);
	ret = tmp_muljoin(to_work, &args);
	va_end(args);
	return (ret);
}