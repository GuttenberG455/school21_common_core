/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:48:23 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/07 20:33:56 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int sym)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == (char) sym)
			return ((char *) &str[i]);
		i++;
	}
	if (sym == 0)
		return ((char *) &str[i]);
	return (0);
}
