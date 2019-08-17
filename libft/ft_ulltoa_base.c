/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:12:16 by forange-          #+#    #+#             */
/*   Updated: 2019/08/17 23:42:25 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_ulltoa_base(unsigned long long dgt, int base)
{
	unsigned long long	temp;
	int					i;
	char				*out;

	i = 0;
	if (base < 2 && base > 16)
		return (NULL);
	if (!dgt)
		return (ft_strdup("0"));
	temp = dgt;
	while (temp)
	{
		temp /= base;
		i++;
	}
	out = (char*)malloc(i + 1);
	out[i] = '\0';
	while (dgt)
	{
		temp = dgt % base;
		out[--i] = (temp > 9) ? (temp - 10) + 'a' : temp + '0';
		dgt /= base;
	}
	return (out);
}
