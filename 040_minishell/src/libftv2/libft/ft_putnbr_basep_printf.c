/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_basep_printf.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:37:25 by ubeetroo          #+#    #+#             */
/*   Updated: 2022/02/17 20:42:59 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	found_trash(char *str)
{
	if (*str == '\0' || *(str + 1) == '\0')
		return (1);
	while (*str)
	{
		if (*str == '+' || *str == '-')
			return (1);
		if (*str <= 32 && *str >= 126)
			return (1);
		++str;
	}
	return (0);
}

static int	found_dupl(char *str, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < len)
	{
		i = j + 1;
		while (i <= len)
		{
			if (str[j] == str[i])
				return (1);
			++i;
		}
		++j;
	}
	return (0);
}

static void	ft_int2base(unsigned long nbrl, unsigned int len, char *base)
{
	if (nbrl < len)
		ft_putchar_fd_p(base[nbrl % len], 1);
	if (nbrl >= len)
	{
		ft_int2base(nbrl / len, len, base);
		ft_putchar_fd_p(base[nbrl % len], 1);
	}
}

static void	ft_int2base_len(unsigned long long nbrl, unsigned int len,
char *base, int *base_num_len)
{
	if (nbrl < len)
		*base_num_len += 1;
	if (nbrl >= len)
	{
		ft_int2base_len(nbrl / len, len, base, base_num_len);
		*base_num_len += 1;
	}
}

int	ft_putnbr_basep_p(unsigned long nbr, char flag)
{
	int		len;
	int		base_num_len;
	char	*base;

	len = 0;
	base_num_len = 0;
	base = "0123456789abcdef";
	if (flag == 'p')
	{
		ft_putstr_fd_p("0x", 1);
		base_num_len = 2;
	}
	if (flag == 'X')
		base = "0123456789ABCDEF";
	while (base[len])
		++len;
	if (found_trash(base) || found_dupl(base, len))
		return (0);
	ft_int2base(nbr, len, base);
	ft_int2base_len(nbr, len, base, &base_num_len);
	return (base_num_len);
}
