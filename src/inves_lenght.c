/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inves_lenght.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:09:25 by altikka           #+#    #+#             */
/*   Updated: 2022/05/11 21:56:08 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hotel(const char **fptr, t_stat *info)
{
	if (*(*fptr + 1) == 'h')
	{
		info->lenght = hh;
		(*fptr) = (*fptr) + 2;
	}
	else
	{
		info->lenght = h;
		(*fptr)++;
	}
	return (1);
}

static int	lima(const char **fptr, t_stat *info)
{
	if (*(*fptr + 1) == 'l')
	{
		info->lenght = ll;
		(*fptr) = (*fptr) + 2;
	}
	else
	{
		info->lenght = l;
		(*fptr)++;
	}
	return (1);
}

int	inves_lenght(const char **fptr, t_stat *info)
{
	if (!(**fptr == 'h' || **fptr == 'l' || **fptr == 'L'))
		return (-1);
	if (**fptr == 'h')
		return (hotel(fptr, info));
	if (**fptr == 'l')
		return (lima(fptr, info));
	if (**fptr == 'L')
	{
		info->lenght = L;
		(*fptr)++;
	}
	return (1);
}
