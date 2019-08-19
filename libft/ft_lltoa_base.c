/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:17:29 by forange-          #+#    #+#             */
/*   Updated: 2019/08/18 21:33:05 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_lltoa_base(long long dgt, int base)
{
	long long	temp;
	int			i;
	char		*out;
	int			is_neg;

	i = 1;
	is_neg = dgt < 0 ? 1 : 0;
	if (base < 2 && base > 16)
		return (NULL);
	if (!dgt)
		return (ft_strdup("0"));
	temp = ft_absll(dgt);
	while ((temp /= base))
		i++;
	out = (char*)ft_memalloc(i + is_neg + 1);
	out[0] = dgt < 0 ? '-' : 0;
	dgt = ft_absll(dgt);
	while (dgt)
	{
		temp = dgt % base;
		out[--i + is_neg] = (temp > 9) ? (temp - 10) + 'a' : temp + '0';
		dgt /= base;
	}
	return (out);
}
