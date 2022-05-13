/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:12:42 by altikka           #+#    #+#             */
/*   Updated: 2022/05/13 08:54:06 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "vec.h"

int	tc_ptr(t_vec *dest, t_stat *info)
{
	//#
	info->lenght = l;
	if (ft_vecncat(dest, "0x", 2) < 0)
		return (-1);
	return (tc_num(dest, info));
}
