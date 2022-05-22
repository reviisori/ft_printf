/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_prefix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 08:54:50 by altikka           #+#    #+#             */
/*   Updated: 2022/05/22 08:58:18 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	format_prefix(t_stat *info, char **pad, char **prefix, size_t len)
{
	char	*temp;

	if (info->width > (info->preci || len) && (info->hash || info->zero))
	{
		temp = *pad;
		if (info->hash && (info->zero || info->preci))
			*pad = ft_strjoin(*prefix, *pad);
		if (info->hash && !info->zero && !info->preci_on)
			*pad = ft_strjoin(*pad, *prefix);
		if (info->hash)
			ft_strdel(&temp);
		return (1);
	}
	return (0);
}

char	*set_prefix(t_stat *info, char *str)
{
	char	*res;

	if (info->type == 'p' || ft_tolower(info->type) == 'x')
	{
		if (info->type == 'X')
			res = ft_strjoin("0X", str);
		else
			res = ft_strjoin("0x", str);
		ft_strdel(&str);
		return (res);
	}
	if (info->type == 'o')
	{
		res = ft_strjoin("0", str);
		ft_strdel(&str);
		return (res);
	}
	return (str);
}
