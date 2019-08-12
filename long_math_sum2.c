/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_math_sum2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 20:15:46 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/08/12 15:52:26 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_dl_lst	*long_math_sum_create_rest_node(t_dl_lst *nbr1, char rest)
{
	t_dl_lst	*dst;
	int			rank;

	if (nbr1->rank != -1)
		rank = nbr1->rank + 1;
	else
		rank = nbr1->rank + 2;
	if (!(dst = dl_lstnew(rest, rank, nbr1->base, NULL)))
		error_func_free(EMPTY_PTR, &nbr1, &dst, NULL);
	return (dst);
}

void			long_math_sum_add_rest(t_dl_lst *nbr1, char rest)
{
	t_dl_lst	*tmp;
	t_dl_lst	*prev;

	if (!nbr1)
		error_func_free(EMPTY_PTR, &nbr1, NULL, NULL);
	if (!(tmp = long_math_sum_create_rest_node(nbr1, rest)))
		error_func_free(EMPTY_PTR, &nbr1, &tmp, NULL);
	if (nbr1->prev)
	{
		prev = nbr1->prev;
		if (prev->rank == tmp->rank)
			long_math_sum_calc(prev, &tmp);
		else
			dl_lst_insert(prev, tmp, nbr1);
	}
	else
	{
		nbr1->prev = tmp;
		tmp->next = nbr1;
	}
}

void			long_math_sum_calc(t_dl_lst *nbr1, t_dl_lst **nbr2)
{
	char		n1;
	char		n2;
	char		rest;
	t_dl_lst	*tmp;

	if (!nbr1 || !nbr2 || !(*nbr2))
		error_func_free(EMPTY_PTR, &nbr1, nbr2, NULL);
	n1 = nbr1->nbr;
	n2 = (*nbr2)->nbr;
	nbr1->nbr = n1 + n2;
	rest = nbr1->nbr / nbr1->base;
	nbr1->nbr = nbr1->nbr % nbr1->base;
	tmp = *nbr2;
	*nbr2 = (*nbr2)->prev;
	if (*nbr2)
		(*nbr2)->next = NULL;
	free(tmp);
	if (rest)
		long_math_sum_add_rest(nbr1, rest);
}
