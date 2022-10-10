/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zalloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rusty <rusty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:54:48 by rusty             #+#    #+#             */
/*   Updated: 2022/03/05 18:01:30 by rusty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ZALLOC_H
# define FT_ZALLOC_H

# include "../libft/libft.h"

typedef struct s_heap	t_heap;

struct					s_heap
{
	void	**mem;
	size_t	count;
	void	*shell;	
};

void	*ft_zalloc(size_t size);
void	ft_free(void);
void	alloc_error(int size);

t_heap					g_heap;

#endif