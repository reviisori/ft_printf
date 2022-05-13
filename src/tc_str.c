/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:45:28 by altikka           #+#    #+#             */
/*   Updated: 2022/05/13 08:21:54 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "vec.h"

int	tc_str(t_vec *dest, t_stat *info)
{
	char	*str;
	size_t	len;

	str = va_arg(info->ap, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (info->preci_on && info->preci < len)
		len = info->preci;
	if (ft_vecncat(dest, str, len) < 0)
		return (-1);
	return (1);
}
