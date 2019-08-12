/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_math_sqr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 15:38:17 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/08/09 13:42:42 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_dl_lst	*long_math_int_to_dl(int nbr, char base)
{
	t_dl_lst	*dst;
	t_dl_lst	*tmp;
	int			rank;

	if (nbr < 0 || base < 2)
		return (NULL);
	dst = NULL;
	rank = 1;
	if (!(dst = dl_lstnew((char)(nbr % (int)base), rank, base, NULL)))
		return (NULL);
	while ((nbr = nbr / (int)base))
	{
		rank++;
		if (nbr % (int)base)
		{
			if (!(tmp = dl_lstnew((char)(nbr % (int)base), rank, base,
						NULL)))
				return (error_return_null_free(&dst, NULL, NULL, NULL));
			tmp->next = dst;
			dst->prev = tmp;
			dst = tmp;
			tmp = NULL;
		}
	}
	return (dst);
}

static t_dl_lst	*long_math_bin_bit_sqrt(char base, int rank)
{
	t_dl_lst	*dst;

	dst = NULL;
	if (!(dst = long_math_sqr((int)(base / 2), base, rank)))
		return (NULL);
	while (dst->next)
		dst = dst->next;
	while (dst->prev)
	{
		dst->rank -= rank + 1;
		dst = dst->prev;
	}
	dst->rank -= rank + 1;
	return (dst);
}

t_dl_lst		*long_math_sqr(int nbr, char base, int rank)
{
	t_dl_lst	*dst;
	t_dl_lst	*tmp;

	if (nbr < 0 || base < 2 || base > 34 || (rank < 0 && nbr != 2))
		return (NULL);
	if (rank < 0)
		return (long_math_bin_bit_sqrt(base, -rank));
	dst = NULL;
	if (!(dst = long_math_int_to_dl(nbr, base)))
		return (NULL);
	if (rank == 0)
	{
		dst->nbr = 1;
		return (dst);
	}
	while (--rank > 0)
	{
		if (!(tmp = long_math_int_to_dl(nbr, base)))
			return (error_return_null_free(&dst, NULL, NULL, NULL));
		if (!(dst = long_math_mult(dst, tmp)))
			return (error_return_null_free(&dst, &tmp, NULL, NULL));
	}
	return (dst);
}
