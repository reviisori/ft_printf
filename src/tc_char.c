/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:06:47 by altikka           #+#    #+#             */
/*   Updated: 2022/05/02 16:11:31 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "vec.h"

int	tc_char(t_vec *dest, t_stat *attr)
{
	char	c;

	c = va_arg(attr->ap, int);
	if (ft_vecpush(dest, &c) < 0)
		return (-1);
	return (1);
}
