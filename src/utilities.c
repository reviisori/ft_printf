/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:30:47 by altikka           #+#    #+#             */
/*   Updated: 2022/05/05 09:47:33 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_stats(t_stat *attr, va_list ap)
{
	va_copy(attr->ap, ap);
	reset_stats(attr);
}

void	reset_stats(t_stat *attr)
{
	attr->val = 0;
	attr->sign = 0;
	attr->is_signed = 0;
	attr->flags = 0;
	attr->width = 0;
	attr->preci = 0;
	attr->preci_on = 0;
	attr->lenght = 0;
	attr->type = ' ';
	attr->pad = ' ';
}
