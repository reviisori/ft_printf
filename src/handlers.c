/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:33:47 by altikka           #+#    #+#             */
/*   Updated: 2022/05/11 11:35:36 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*handle_char(t_stat *info)
{
	char	*str;

	info->val = va_arg(info->ap, int);
	info->sign = 1 - (2 * (info->val < 0));
	if (info->is_signed)
		info->val *= info->sign;
	str = ft_anytoa((unsigned char ) info->val,
			set_base(info->type), info->sign, (info->type == 'X'));
	if (!str)
		return (NULL);
	return (str);
}

char	*handle_short(t_stat *info)
{
	char	*str;

	info->val = va_arg(info->ap, int);
	info->sign = 1 - (2 * (info->val < 0));
	if (info->is_signed)
		info->val *= info->sign;
	str = ft_anytoa((unsigned short ) info->val,
			set_base(info->type), info->sign, (info->type == 'X'));
	if (!str)
		return (NULL);
	return (str);
}

char	*handle_int(t_stat *info)
{
	char	*str;

	info->val = va_arg(info->ap, int);
	info->sign = 1 - (2 * (info->val < 0));
	if (info->is_signed)
		info->val *= info->sign;
	str = ft_anytoa(info->val,
			set_base(info->type), info->sign, (info->type == 'X'));
	if (!str)
		return (NULL);
	return (str);
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
	return (str);
}
