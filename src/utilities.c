/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:30:47 by altikka           #+#    #+#             */
/*   Updated: 2022/05/09 13:57:32 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_base(const char c)
{
	if (c == 'x' || c == 'X' || c == 'p')
		return (16);
	else if (c == 'o')
		return (8);
	else
		return (10);
}

void	init_stats(t_stat *info, va_list ap)
{
	va_copy(info->ap, ap);
	reset_stats(info);
}

void	reset_stats(t_stat *info)
{
	info->val = 0;
	info->sign = 0;
	info->is_signed = false;
	info->hash = false;
	info->dash = false;
	info->plus = false;
	info->space = false;
	info->zero = false;
	info->width = 0;
	info->preci = 0;
	info->preci_on = false;
	info->lenght = 0;
	info->type = ' ';
	info->pad = ' ';
}
