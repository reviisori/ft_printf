/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:12:15 by altikka           #+#    #+#             */
/*   Updated: 2022/05/02 16:12:32 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "vec.h"

int	tc_num(t_vec *dest, t_stat *attr)
{
	size_t	len;
	char	type;

	len = dest->len;
	type = attr->type;
	ft_putendl("NUM - nothing here yet");
	return (1);
}
