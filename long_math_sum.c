/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_math_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 11:45:37 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/08/14 13:31:59 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		long_math_sum_steal_node(t_dl_lst *nbr1, t_dl_lst **nbr2)
{
	t_dl_lst	*tmp1;
	t_dl_lst	*tmp2;

	tmp1 = nbr1->next;
	tmp2 = (*nbr2)->prev;
	tmp1->prev = *nbr2;
	(*nbr2)->next = tmp1;
	nbr1->next = (*nbr2);
	(*nbr2)->prev = nbr1;
	if (!tmp2)
		return (1);
	*nbr2 = tmp2;
	return (0);
}

static int		long_math_sum_start(t_dl_lst **nbr1, t_dl_lst **nbr2)
{
	t_dl_lst	*tmp;

	if (!nbr1 || !(*nbr1) || !nbr2 || !(*nbr2))
		error_func_free(EMPTY_PTR, nbr1, nbr2, NULL);
	while ((*nbr1)->next)
		*nbr1 = (*nbr1)->next;
	while ((*nbr2)->next)
		*nbr2 = (*nbr2)->next;
	if ((*nbr1)->rank > (*nbr2)->rank)
	{
		while ((*nbr1)->rank > (*nbr2)->rank && (*nbr2)->prev)
			*nbr2 = (*nbr2)->prev;
		if ((*nbr1)->rank <= (*nbr2)->rank)
			*nbr2 = (*nbr2)->next;
		tmp = (*nbr2)->prev;
		(*nbr2)->prev = *nbr1;
		(*nbr1)->next = *nbr2;
		*nbr2 = tmp;
		if (*nbr2 == NULL)
			return (1);
		(*nbr2)->next = NULL;
	}
	return (0);
}

static t_dl_lst	*long_math_eat_head(t_dl_lst *nbr1, t_dl_lst *nbr2)
{
	nbr1->prev = nbr2;
	nbr2->next = nbr1;
	return (nbr1);
}

t_dl_lst		*long_math_sum(t_dl_lst *nbr1, t_dl_lst *nbr2)
{
	char		rest;

	if (!nbr1 || !nbr2)
		error_func_free(EMPTY_PTR, &nbr1, &nbr2, NULL);
	if (long_math_sum_start(&nbr1, &nbr2))
		return (nbr1);
	rest = 0;
	while (nbr2)
	{
		if (nbr1->rank == nbr2->rank)
			long_math_sum_calc(nbr1, &nbr2);
		else if (nbr1->rank < nbr2->rank)
		{
			if (nbr1->prev)
				nbr1 = nbr1->prev;
			else
				return (long_math_eat_head(nbr1, nbr2));
		}
		else
		{
			if (long_math_sum_steal_node(nbr1, &nbr2))
				return (nbr1);
		}
	}
	return (nbr1);
}
