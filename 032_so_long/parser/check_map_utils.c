/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:25:51 by majacqua          #+#    #+#             */
/*   Updated: 2021/11/16 18:32:19 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.h"

int	is_ch_in_str(const char *str, int ch)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (char) ch)
			return (1);
		i++;
	}
	return (0);
}
