/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:17:29 by forange-          #+#    #+#             */
/*   Updated: 2019/08/10 17:26:49 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_lltoa_base(long long dgt, int base)
{
	long long	temp;
	int			i;
	char		*out;

	i = 0;
	if (base < 2 && base > 16)
		return (NULL);
	temp = ft_absll(dgt);
	while (temp)
	{
		temp /= base;
		i++;
	}
	out = (char*)malloc(i + (dgt < 0 ? 2 : 1));
	out[i] = '\0';
	out[0] = dgt < 0 ? '-' : 0;
	dgt = ft_absll(dgt);
	while (dgt)
	{
		temp = dgt % base;
		out[--i] = (temp > 9) ? (temp - 10) + 'a' : temp + '0';
		dgt /= base;
	}
	return (out);
}
