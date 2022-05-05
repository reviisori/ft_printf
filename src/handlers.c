/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:33:47 by altikka           #+#    #+#             */
/*   Updated: 2022/05/05 16:31:33 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*handle_char(t_stat *attr)
{
	attr->val = 0;
	ft_putendl("[hh]: Wrong castle Mario.");
	return (NULL);
}

char	*handle_short(t_stat *attr)
{
	attr->val = 0;
	ft_putendl("[h]: Wrong castle Mario.");
	return (NULL);
}

char	*handle_int(t_stat *attr)
{
	char	*str;

	attr->val = va_arg(attr->ap, int);
	attr->sign = (1 - 2 * (attr->val < 0));
	if (attr->is_signed)
		attr->val *= attr->sign;
	str = ft_anytoa(attr->val,
			set_base(attr->type), attr->sign, (attr->type == 'X'));
	if (!str)
		return (NULL);
	return (str);
}

char	*handle_long(t_stat *attr)
{
	attr->val = 0;
	ft_putendl("[ll][l][L]: Wrong castle Mario.");
	return (NULL);
}
