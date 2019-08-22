/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_math_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 12:42:18 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/08/22 11:22:39 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				long_math_strlen(t_dl_lst *lst, t_printf *tprintf, t_sem sem)
{
	int				start;
	int				add;

	add = 1;
	if (sem.s || tprintf->flag & F_PLUS)
		add = 2;
	while (lst->prev)
		lst = lst->prev;
	start = lst->rank;
	while (lst->next)
		lst = lst->next;
	if (tprintf->prec < 0 || !(tprintf->flag & F_PREC))
		tprintf->prec = STANDART_PRECISION;
	if (tprintf->prec == 0 && !(tprintf->flag & F_HASH))
		tprintf->prec = -1;
	if (start > 0)
		return (start + tprintf->prec + add);
	else
		return (tprintf->prec + add + 1);
}

static t_dl_lst	*turn_sem_to_lst(t_dl_lst *lst, t_sem sem, int *rank,
		int *bit)
{
	t_dl_lst	*n_lst;

	if (!rank || !bit)
		error_func_free(EMPTY_PTR, &lst, NULL, NULL);
	if (*bit < 0 || (*rank < 0 && (sem.base % 2)))
		return (lst);
	if (sem.m & (size_t)1 << *bit)
	{
		n_lst = NULL;
		if (!(n_lst = long_math_sqr(2, sem.base, *rank)))
			error_func_free(EMPTY_PTR, &lst, &n_lst, NULL);
		if (!lst)
			lst = n_lst;
		else
		{
			if (!(lst = long_math_sum(lst, n_lst)))
				error_func_free(EMPTY_PTR, &lst, &n_lst, NULL);
		}
	}
	(*rank)--;
	(*bit)--;
	return (turn_sem_to_lst(lst, sem, rank, bit));
}

static int		fill_sem(t_sem *sem, void *void_ptr, char base)
{
	size_t			*szt_ptr;

	if (!sem || !void_ptr)
	{
		ft_putstr(EMPTY_PTR);
		exit(1);
	}
	sem->base = base;
	szt_ptr = (size_t *)((char *)void_ptr + 2);
	sem->s = (*szt_ptr) >> 63;
	szt_ptr = (size_t *)((char *)void_ptr + 8);
	sem->e = *szt_ptr;
	sem->e &= 32767;
	szt_ptr = void_ptr;
	sem->m = *szt_ptr;
	return ((int)(sem->e - 16383));
}

char			*turn_flpoint_to_str(long double ld, char base,
		t_printf *tprintf)
{
	t_sem			sem;
	t_dl_lst		*nbr_lst;
	char			*dst;
	int				rank;
	int				bit;

	if (base > 16 || base < 2)
		error_func_free(WRONG_VAL, NULL, NULL, NULL);
	bit = 63;
	if (ld != ld || (ld != 0 && ld == ld * 10))
		return (nan_inf(ld, tprintf));
	rank = fill_sem(&sem, &ld, base);
	nbr_lst = NULL;
	if (ld != 0)
		nbr_lst = turn_sem_to_lst(NULL, sem, &rank, &bit);
	if (ld == 0 || !nbr_lst)
	{
		if (!(nbr_lst = dl_lstnew(0, 1, base, NULL)))
			error_func_free(EMPTY_PTR, &nbr_lst, NULL, NULL);
	}
	dst = turn_dl_lst_to_str(nbr_lst, *tprintf, sem);
	return (dst);
}
