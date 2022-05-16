/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coat_nums_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 10:39:26 by altikka           #+#    #+#             */
/*   Updated: 2022/05/16 13:44:58 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*format_sign(t_stat *info)
{
	char	*sign;

	sign = NULL;
	if (info->sign == -1)
	{
		sign = ft_strnew(1);
		*sign = '-';
	}
	return (sign);
}

static char	*format_preci(t_stat *info, size_t len)
{
	char	*sign;
	char	*pad;
	char	*res;

	sign = format_sign(info);
	if (info->preci > len)
	{
		len = info->preci - len;
		pad = ft_strnew(len);
		ft_memset(pad, '0', len);
		res = ft_strjoin(sign, pad);
		ft_strdel(&pad);
		return (res);
	}
	return (sign);
}

/*
static char	*format_prefix(t_stat *info, size_t len)
{
	return ();
}
*/

char	*coat_nums_front(t_stat *info, size_t len)
{
	char	*pad;

	pad = NULL;
	//format_prefix();
	pad = format_preci(info, len);
	//format_width();
	return (pad);
}
