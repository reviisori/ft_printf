/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:06:47 by altikka           #+#    #+#             */
/*   Updated: 2022/05/18 15:24:44 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "vec.h"

int	tc_char(t_vec *dest, t_stat *info)
{
	char	c;

	c = va_arg(info->ap, int);
	if (pad(dest, (info->width - 1), info->pad, !(info->dash)) < 0)
		return (-1);
	if (ft_vecpush(dest, &c) < 0)
		return (-1);
	if (pad(dest, (info->width - 1), info->pad, (info->dash)) < 0)
		return (-1);
	return (1);
}
