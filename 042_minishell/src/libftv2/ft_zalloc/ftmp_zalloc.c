/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmp_zalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:20:18 by majacqua          #+#    #+#             */
/*   Updated: 2022/02/23 13:19:57 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_zalloc.h"

extern t_heap	g_heap;

void	ftmp_free(void)
{
	size_t	i;

	i = 0;
	while (i < g_heap.tmp_count)
		free(g_heap.tmp_mem[i++]);
	free(g_heap.tmp_mem);
}

void	ftmp_add(void *ptr)
{
	void		**new;
	size_t		i;

	new = malloc(sizeof(void *) * (g_heap.tmp_count + 1));
	if (!new)
		alloc_error(sizeof(void *) * (g_heap.tmp_count + 1));
	i = 0;
	while (i < g_heap.tmp_count)
	{
		new[i] = g_heap.tmp_mem[i];
		i++;
	}
	new[g_heap.tmp_count] = ptr;
	g_heap.tmp_count++;
	if (g_heap.tmp_mem)
		free(g_heap.tmp_mem);
	g_heap.tmp_mem = new;
}

void	*ftmp_zalloc(size_t size)
{
	void	*ptr;

	if (!g_heap.tmp_count)
	{
		g_heap.tmp_count = 0;
		g_heap.tmp_mem = NULL;
	}
	ptr = malloc(size);
	if (!ptr)
		alloc_error(size);
	ftmp_add(ptr);
	ft_bzero(ptr, size);
	return (ptr);
}
