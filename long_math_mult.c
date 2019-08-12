/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_math_mult.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 12:16:10 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/08/12 15:56:05 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_dl_lst	*long_math_mult_shifter(t_dl_lst **nbr1, t_dl_lst **nbr2,
		t_dl_lst *answer)
{
	t_dl_lst	*tmp;

	if (!nbr1 || !(*nbr1) || !nbr2 || !(*nbr2) || !answer)
		error_func_free_lst(EMPTY_PTR, nbr1, nbr2, &answer);
	tmp = *nbr2;
	*nbr2 = (*nbr2)->prev;
	free(tmp);
	while ((*nbr1)->next)
		*nbr1 = (*nbr1)->next;
	if (*nbr2)
	{
		(*nbr2)->next = NULL;
		if (!(answer = dl_lstnew(0, (*nbr1)->rank + (*nbr2)->rank - 1,
						(*nbr1)->base, NULL)))
			error_func_free_lst(EMPTY_PTR, nbr1, nbr2, &tmp);
	}
	return (answer);
}

static t_dl_lst	*long_math_mult_get_answer_lst(t_dl_lst *nbr1, t_dl_lst *nbr2,
		t_dl_lst *answer)
{
	t_dl_lst	*dst;

	if (!answer || !nbr1 || !nbr2)
	{
		if (!answer)
			free(answer);
		error_func_free(EMPTY_PTR, &nbr1, &nbr2, NULL);
	}
	while (answer->next)
		answer = answer->next;
	while (answer->rank < nbr1->rank + nbr2->rank - 1 && answer->prev)
		answer = answer->prev;
	if (answer->rank != nbr1->rank + nbr2->rank - 1)
	{
		answer->prev = dl_lstnew(0, nbr1->rank + nbr2->rank - 1, nbr1->base,
				NULL);
		dst = answer->prev;
		dst->next = answer;
	}
	else
		dst = answer;
	return (dst);
}

static t_dl_lst	*long_math_mult_solve_one_bit(t_dl_lst **nbr1,
		t_dl_lst *nbr2, t_dl_lst *answer)
{
	char		rest;

	if (!nbr1 || !(*nbr1) || !nbr2 || !answer)
		error_func_free_lst(EMPTY_PTR, nbr1, &nbr2, &answer);
	while (1)
	{
		if (!(answer = long_math_mult_get_answer_lst(*nbr1, nbr2, answer)))
			error_func_free(EMPTY_PTR, nbr1, &nbr2, NULL);
		answer->nbr = (nbr2->nbr) * ((*nbr1)->nbr) + answer->nbr;
		rest = answer->nbr / answer->base;
		answer->nbr = answer->nbr % answer->base;
		if (rest)
			long_math_sum_add_rest(answer, rest);
		if ((*nbr1)->prev)
			*nbr1 = (*nbr1)->prev;
		else
			break ;
	}
	return (answer);
}

static t_dl_lst	*long_math_mult_prepare(t_dl_lst **nbr1, t_dl_lst **nbr2)
{
	t_dl_lst	*dst;

	if (!nbr1 || !(*nbr1) || !nbr2 || !(*nbr2))
		error_func_free(EMPTY_PTR, nbr1, nbr2, NULL);
	while ((*nbr1)->next)
		*nbr1 = (*nbr1)->next;
	while ((*nbr2)->next)
		*nbr2 = (*nbr2)->next;
	if (!(dst = dl_lstnew(0, (*nbr1)->rank + (*nbr2)->rank - 1,
					(*nbr1)->base, NULL)))
		error_func_free(EMPTY_PTR, nbr1, nbr2, NULL);
	return (dst);
}

t_dl_lst		*long_math_mult(t_dl_lst *nbr1, t_dl_lst *nbr2)
{
	t_dl_lst	*answer;
	t_dl_lst	*bufer;

	if (!(answer = long_math_mult_prepare(&nbr1, &nbr2)) || !nbr1 || !nbr2)
		error_func_free_lst(EMPTY_PTR, &nbr1, &nbr2, &answer);
	bufer = NULL;
	while (nbr2)
	{
		if (!(answer = long_math_mult_solve_one_bit(&nbr1, nbr2, answer)))
			error_func_free(EMPTY_PTR, &nbr1, &nbr2, NULL);
		if (bufer)
			answer = long_math_sum(answer, bufer);
		bufer = answer;
		if (!(answer = long_math_mult_shifter(&nbr1, &nbr2, answer))
				|| !nbr1)
		{
			if (bufer)
				free(bufer);
			error_func_free_lst(EMPTY_PTR, &nbr1, &nbr2, &answer);
		}
	}
	dl_lstdel(nbr1);
	answer = dl_lstdel_if_zero(answer);
	return (answer);
}
