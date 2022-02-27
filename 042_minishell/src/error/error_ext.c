/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:31:07 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/25 16:35:51 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	err_ext_return_one(char *module, char *text, char *name);
{
	ft_putstr_fd(module, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(text, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}