/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zalloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:21:29 by majacqua          #+#    #+#             */
/*   Updated: 2022/07/25 13:44:07 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zalloc.h"

void	ft_free(void)
{
	size_t	i;

	i = 0;
	while (i < g_heap.count)
		free(g_heap.mem[i++]);
	free(g_heap.mem);
}

void	alloc_error(int size)
{
	ft_putstr_fd("ft_zalloc: cannot allocate ", 2);
	ft_putnbr_fd(size, 2);
	ft_putstr_fd("bytes", 2);
	ft_free();
	exit(2);
}

void	add(void *ptr)
{
	void		**new;
	size_t		i;

	new = malloc(sizeof(void *) * (g_heap.count + 1));
	if (!new)
		alloc_error(sizeof(void *) * (g_heap.count + 1));
	i = 0;
	while (i < g_heap.count)
	{
		new[i] = g_heap.mem[i];
		i++;
	}
	new[g_heap.count] = ptr;
	g_heap.count++;
	if (g_heap.mem)
		free(g_heap.mem);
	g_heap.mem = new;
}

void	*ft_zalloc(size_t size)
{
	void	*ptr;

	if (!g_heap.count)
	{
		g_heap.count = 0;
		g_heap.mem = NULL;
	}
	ptr = malloc(size);
	if (!ptr)
		alloc_error(size);
	add(ptr);
	ft_bzero(ptr, size);
	return (ptr);
}