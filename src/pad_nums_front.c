/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_nums_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:40:33 by altikka           #+#    #+#             */
/*   Updated: 2022/05/27 19:15:02 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static inline int	is_sign_added(t_stat *info)
{
	return ((info->sign < 0 || info->plus || info->space));
}

static char	*format_width(t_stat *info, char *pad, size_t len)
{
	char	*temp;
	char	*res;

	if (!info->dash && info->width > len
		&& info->width > (info->preci + is_sign_added(info)))
	{
		if (info->preci)
			len = info->width - info->preci - is_sign_added(info);
		else
			len = info->width - len - is_sign_added(info);
		temp = ft_strnew(len);
		if ((info->zero && !info->hash) || info->width > info->preci)
			info->pad = ' ';
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

	sign = ft_strnew(1);
	if (info->sign == -1)
		*sign = '-';
	if (info->space && info->sign != -1 && info->is_signed)
		*sign = ' ';
	if (info->plus && info->sign != -1 && info->is_signed)
		*sign = '+';
	if (*sign == '\0')
		ft_strdel(&sign);
	return (sign);
}

static char	*format_preci(t_stat *info, size_t len)
{
	char	*sign;
	char	*temp;
	char	*res;

	sign = format_sign(info);
	if (info->zero && info->width && !info->preci && !info->preci_on)
		info->preci = info->width - is_sign_added(info);
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

static char	*format_prefix(t_stat *info, char *pad)
{
	char	*res;

	if (info->hash)
	{
		if (info->type == 'p' || (ft_tolower(info->type) == 'x' && info->val))
		{
			if (info->type == 'X')
				res = ft_strjoin("0X", pad);
			else
				res = ft_strjoin("0x", pad);
			ft_strdel(&pad);
			return (res);
		}
		if (info->type == 'o' && info->val)
		{
			res = ft_strjoin("0", pad);
			ft_strdel(&pad);
			return (res);
		}
	}
	return (pad);
}

char	*pad_nums_front(t_stat *info, size_t len)
{
	size_t	px_len;
	char	*pad;

	if (!info->val && info->type != 'p')
		info->hash = false;
	if (info->hash)
	{
		px_len = 2 - 1 * (info->type == 'o');
		if (!info->dash && info->preci_on
			&& (info->width >= px_len + info->preci))
			info->width -= px_len;
		else if (info->preci
			&& (info->type == 'x' || info->type == 'X' || info->type == 'p'))
			px_len = 0;
		else
			len += px_len;
	}
	pad = format_preci(info, len);
	pad = format_prefix(info, pad);
	pad = format_width(info, pad, len);
	return (pad);
}
