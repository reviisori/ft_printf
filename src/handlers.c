/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:33:47 by altikka           #+#    #+#             */
/*   Updated: 2022/05/13 20:02:05 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*pad_num(t_stat *info, char *str)
{
	char			*pad;
	char			*res;
	size_t			len;

	if (!info->val && info->preci_on)
	{
		*str = '\0';
		return (str);
	}
	if (info->preci_on)
	{
		len = ft_strlen(str);
		if (info->preci > len)
		{
			//maybe call mum
			len = info->preci - len;
			pad = ft_strnew(len);
			ft_memset(pad, '0', len);
			res = ft_strjoin(pad, str);
			ft_strdel(&pad);
			ft_strdel(&str);
			return (res);
		}
	}
	return (str);
}

char	*handle_char(t_stat *info)
{
	char	*str;

	info->val = va_arg(info->ap, int);
	info->sign = 1 - (2 * ((char ) info->val < 0));
	if (info->is_signed)
		info->val *= info->sign;
	str = ft_anytoa((unsigned char ) info->val,
			set_base(info->type), info->sign, (info->type == 'X'));
	if (!str)
		return (NULL);
	return (pad_num(info, str));
}

char	*handle_short(t_stat *info)
{
	char	*str;

	info->val = va_arg(info->ap, int);
	info->sign = 1 - (2 * ((short ) info->val < 0));
	if (info->is_signed)
		info->val *= info->sign;
	str = ft_anytoa((unsigned short ) info->val,
			set_base(info->type), info->sign, (info->type == 'X'));
	if (!str)
		return (NULL);
	return (pad_num(info, str));
}

char	*handle_int(t_stat *info)
{
	char	*str;

	info->val = va_arg(info->ap, int);
	info->sign = 1 - (2 * (info->val < 0));
	if (info->is_signed)
		info->val *= info->sign;
	str = ft_anytoa((unsigned int )info->val,
			set_base(info->type), info->sign, (info->type == 'X'));
	if (!str)
		return (NULL);
	return (pad_num(info, str));
}

char	*handle_long(t_stat *info)
{
	char	*str;

	info->val = va_arg(info->ap, long);
	info->sign = 1 - (2 * (info->val < 0));
	if (info->is_signed)
		info->val *= info->sign;
	str = ft_anytoa((unsigned long ) info->val,
			set_base(info->type), info->sign, (info->type == 'X'));
	if (!str)
		return (NULL);
	return (pad_num(info, str));
}
