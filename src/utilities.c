/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:30:47 by altikka           #+#    #+#             */
/*   Updated: 2022/05/05 12:24:32 by altikka          ###   ########.fr       */
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

void	init_stats(t_stat *attr, va_list ap)
{
	va_copy(attr->ap, ap);
	reset_stats(attr);
}

void	reset_stats(t_stat *attr)
{
	attr->val = 0;
	attr->sign = 0;
	attr->is_signed = false;
	attr->hash = false;
	attr->dash = false;
	attr->plus = false;
	attr->space = false;
	attr->zero = false;
	attr->width = 0;
	attr->preci = 0;
	attr->preci_on = false;
	attr->lenght = 0;
	attr->type = ' ';
	attr->pad = ' ';
}
