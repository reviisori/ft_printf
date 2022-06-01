/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:57:06 by altikka           #+#    #+#             */
/*   Updated: 2022/06/01 17:03:39 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	lima_ptr(t_vec *dest, t_stat *info)
{
	long		*lptr;

	lptr = va_arg(info->ap, long *);
	*lptr = (long ) dest->len;
	return (1);
}

static int	hotel_ptr(t_vec *dest, t_stat *info)
{
	signed char	*cptr;
	short		*sptr;

	if (info->lenght == hh)
	{
		cptr = va_arg(info->ap, signed char *);
		*cptr = (signed char ) dest->len;
	}
	else
	{
		sptr = va_arg(info->ap, short *);
		*sptr = (short ) dest->len;
	}
	return (1);
}

int	tc_len(t_vec *dest, t_stat *info)
{
	int			*iptr;

	if (info->lenght == hh || info->lenght == h)
		return (hotel_ptr(dest, info));
	else if (info->lenght == l)
		return (lima_ptr(dest, info));
	else
	{
		iptr = va_arg(info->ap, int *);
		*iptr = (int ) dest->len;
	}
	return (1);
}
