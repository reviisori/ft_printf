/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_dbl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:10:57 by altikka           #+#    #+#             */
/*   Updated: 2022/05/09 14:30:12 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "vec.h"

static int	pad_dbl(t_vec *dest, size_t dec_len, t_stat *info)
{
	unsigned int	pad;

	pad = info->preci - dec_len;
	while (pad-- > 0)
		if (ft_vecpush(dest, "0") < 0)
			return (-1);
	return (1);
}

static int	add_parts(t_vec *dest, char *whl, char *dec, t_stat *info)
{
	size_t	whl_len;
	size_t	dec_len;

	whl_len = ft_strlen(whl);
	dec_len = ft_strlen(dec);
	if (ft_vecncat(dest, whl, whl_len) < 0)
	{
		ft_strdel(&whl);
		ft_strdel(&dec);
		return (-1);
	}
	ft_strdel(&whl);
	if (ft_vecpush(dest, ".") < 0)
		return (-1);
	if (pad_dbl(dest, dec_len, info) < 0)
		return (-1);
	if (ft_vecncat(dest, dec, dec_len) < 0)
	{
		ft_strdel(&dec);
		return (-1);
	}
	ft_strdel(&dec);
	return (1);
}

static int	get_and_round(t_vec *dest, long double val, t_stat *info)
{
	char			*whl;
	char			*dec;
	long double		d;
	unsigned int	mdl;

	whl = ft_anytoa((unsigned long ) val, 10, info->sign, false);
	d = (val - (unsigned long ) val) * ft_pow(10, info->preci + 1);
	mdl = (unsigned long ) d % 10;
	if (mdl >= 5)
	{
		d = (d / 10) + 1;
		if ((unsigned int ) ft_intlen(d) > info->preci)
		{
			ft_strdel(&whl);
			whl = ft_anytoa((unsigned long ) val + 1, 10, info->sign, false);
			d = 0;
		}
	}
	else
		d /= 10;
	dec = ft_anytoa((unsigned long ) d, 10, 1, false);
	return (add_parts(dest, whl, dec, info));
}

int	tc_dbl(t_vec *dest, t_stat *info)
{
	long double		val;
	t_vec			temp;

	val = va_arg(info->ap, double);
	info->sign = 1 - 2 * (val < 0);
	if (val < 0)
		val *= info->sign;
	info->preci = 6 * !info->preci_on + info->preci;
	if (ft_vecnew(&temp, 1, sizeof(char)) < 0)
		return (-1);
	if (get_and_round(&temp, val, info) < 0)
		return (-1);
	if (ft_vecappend(dest, &temp) < 0)
		return (-1);
	ft_vecdel(&temp);
	return (1);
}
