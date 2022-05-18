/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:12:15 by altikka           #+#    #+#             */
/*   Updated: 2022/05/18 14:44:16 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "vec.h"

int	tc_num(t_vec *dest, t_stat *info)
{
	char	*str;
	size_t	len;

	str = g_handler[info->lenght](info);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	if (ft_vecncat(dest, str, len) < 0)
	{
		ft_strdel(&str);
		return (-1);
	}
	ft_strdel(&str);
	if (pad(dest, info->width - len, info->pad, (info->dash)) < 0)
		return (-1);
	return (1);
}
