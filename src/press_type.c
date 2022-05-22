/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:17:17 by altikka           #+#    #+#             */
/*   Updated: 2022/05/22 09:38:43 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	get_index(const char c)
{
	char	*p;

	p = ft_strcasechr(TYPES, c);
	if (!p)
		return (-1);
	return (p - TYPES);
}

int	press_type(t_vec *dest, const char **fptr, t_stat *info)
{
	t_jump	disp;
	int		i;

	info->type = *(*fptr)++;
	if (info->type == 'd' || info->type == 'i' || info->type == 'f')
		info->is_signed = true;
	i = get_index(info->type);
	if (i < 0)
	{
		if (info->type == '%')
			return (pad_char(dest, info, '%'));
		//DELETE
		ft_putendl("*ERROR*: format not supported");
		return (-1);
	}
	disp = g_jump[i];
	return (disp(dest, info));
}
