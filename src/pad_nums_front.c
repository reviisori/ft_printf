/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_nums_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:40:33 by altikka           #+#    #+#             */
/*   Updated: 2022/05/19 13:49:44 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*format_width(t_stat *info, char *pad, size_t len)
{
	char	*temp;
	char	*res;

	if (!info->dash && info->width > len
		&& info->width > (info->preci + (info->sign < 0)))
	{
		if (info->preci)
			len = info->width - info->preci - (info->sign < 0);
		else
			len = info->width - len - (info->sign < 0);
		temp = ft_strnew(len);
		ft_memset(temp, info->pad, len);
		res = ft_strjoin(temp, pad);
		ft_strdel(&temp);
		ft_strdel(&pad);
		return (res);
	}
	return (pad);
}

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
	char	*temp;
	char	*res;

	sign = format_sign(info);
	if (info->preci > len)
	{
		len = info->preci - len;
		temp = ft_strnew(len);
		ft_memset(temp, '0', len);
		res = ft_strjoin(sign, temp);
		ft_strdel(&temp);
		ft_strdel(&sign);
		return (res);
	}
	else
		info->preci = 0;
	return (sign);
}

char	*pad_nums_front(t_stat *info, size_t len)
{
	char	*pad;

	pad = format_preci(info, len);
	pad = format_width(info, pad, len);
	return (pad);
}
