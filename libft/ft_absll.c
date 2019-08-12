/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:27:03 by bsabre-c          #+#    #+#             */
/*   Updated: 2018/12/11 14:43:04 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_absll(long long n)
{
	unsigned long long	dst;

	if (n < 0)
		dst = (unsigned long long)(-n);
	else
		dst = (unsigned long long)n;
	return (dst);
}
