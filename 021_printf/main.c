/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:52:33 by majacqua          #+#    #+#             */
/*   Updated: 2021/10/21 16:41:43 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int				count = 0;
	char 			ch = '*';
	int				dec = 143100;
	int				in = -2147483648;
	int				*ptr = &dec;
	char			*str = "StRoKa";
	unsigned int	unint = 4123456789;
	int				hexa = 0xf0a01;
	// int				count = 0;
	// char 			ch = 0;
	// int				dec = 0;
	// int				in = 0;
	// int				*ptr = 0;
	// char			*str = 0;
	// unsigned int	unint = 0;
	// int				hexa = 0x0;

	count = ft_printf("FIVE-%%-%c-%d-%i-%p-%s-%u-%x-%X", ch, dec, in, ptr, str, unint, hexa, hexa);
	printf("\n[%d] - len\n", count);
	count = printf("FIVE-%%-%c-%d-%i-%p-%s-%u-%x-%X", ch, dec, in, ptr, str, unint, hexa, hexa);
	printf("\n[%d] - len\n", count);
	// count = ft_printf("a%%%=", hexa);
	// printf("\n[%d] - len\n", count);

}