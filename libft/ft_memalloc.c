/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:47:29 by bsabre-c          #+#    #+#             */
/*   Updated: 2018/11/30 16:21:21 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*dst;
	size_t	i;

	if (!(dst = (char *)malloc(size)))
		return (NULL);
	i = 0;
	ft_memset(dst, 0, size);
	return (dst);
}
