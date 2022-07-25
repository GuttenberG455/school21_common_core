/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zalloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacqua <majacqua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:44:02 by majacqua          #+#    #+#             */
/*   Updated: 2022/07/25 13:44:03 by majacqua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include "../libft.h"

typedef struct s_heap
{
	void	**mem;
	size_t	count;
}	t_heap;

t_heap	g_heap;

void	*ft_zalloc(size_t size);
void	ft_free(void);

#endif