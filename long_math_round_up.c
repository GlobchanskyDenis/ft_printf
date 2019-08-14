/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_math_round_up.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:53:11 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/08/14 13:34:12 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	round_up_little_dl_lst(t_dl_lst **lst, int precision)
{
	t_dl_lst	*tmp;

	if (!lst || !(*lst))
		error_func_free(EMPTY_PTR, NULL, NULL, NULL);
	if (((*lst)->rank == -precision - 1) && (((*lst)->nbr > (*lst)->base / 2) \
				|| ((*lst)->nbr == (*lst)->base / 2 && (*lst)->next)))
	{
		if (precision == 0)
			precision = -1;
		if (!(tmp = dl_lstnew(1, -precision, (*lst)->base, NULL)))
			error_func_free(EMPTY_PTR, lst, NULL, NULL);
		dl_lstdel(*lst);
		*lst = tmp;
		return ;
	}
	if (!(tmp = dl_lstnew(0, 1, (*lst)->base, NULL)))
		error_func_free(EMPTY_PTR, lst, NULL, NULL);
	dl_lstdel(*lst);
	*lst = tmp;
}

static int	is_needed_to_round(t_dl_lst *lst, t_dl_lst *tmp, int precision)
{
	if (!lst || !tmp)
		return (0);
	if (tmp->rank == -precision - 1)
	{
		if (tmp->nbr > tmp->base / 2)
			return (1);
		else if (tmp->nbr == tmp->base / 2 && tmp->next)
			return (1);
		else if (tmp->nbr == tmp->base / 2 && (lst->rank == -precision || \
					(lst->rank == 1 && precision == 0)) && lst->nbr % 2)
			return (1);
	}
	return (0);
}

void		round_up_dl_lst(t_dl_lst **lst, int precision)
{
	t_dl_lst	*tmp;

	if (!lst || !(*lst))
		error_func_free(EMPTY_PTR, NULL, NULL, NULL);
	*lst = dl_lstdel_if_zero(*lst);
	while ((*lst)->rank < -precision && (*lst)->prev)
		*lst = (*lst)->prev;
	if ((*lst)->rank < -precision)
	{
		round_up_little_dl_lst(lst, precision);
		return ;
	}
	while ((*lst)->rank >= -precision && (*lst)->next)
		*lst = (*lst)->next;
	if ((*lst)->rank >= -precision)
		return ;
	tmp = *lst;
	*lst = (*lst)->prev;
	if (is_needed_to_round(*lst, tmp, precision))
		long_math_sum_add_rest(tmp, 1);
}
