/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_dbl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:10:57 by altikka           #+#    #+#             */
/*   Updated: 2022/05/12 12:33:18 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "vec.h"

static int	pad_after_point(t_vec *dest, size_t dec_len, t_stat *info)
{
	int	pad;

	pad = info->preci - (int ) dec_len;
	while (pad-- > 0)
		if (ft_vecpush(dest, "0") < 0)
			return (-1);
	return (1);
}

static int	add_point(t_vec *dest, char *dec, size_t dec_len, t_stat *info)
{
	if (info->preci != 0)
	{
		if (ft_vecpush(dest, ".") < 0)
		{
			ft_strdel(&dec);
			ft_vecdel(dest);
			return (-1);
		}
		if (pad_after_point(dest, dec_len, info) < 0)
		{
			ft_strdel(&dec);
			ft_vecdel(dest);
			return (-1);
		}
	}
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
		ft_vecdel(dest);
		return (-1);
	}
	ft_strdel(&whl);
	if (add_point(dest, dec, dec_len, info) < 0)
		return (-1);
	if (info->preci != 0 && ft_vecncat(dest, dec, dec_len) < 0)
	{
		ft_strdel(&dec);
		ft_vecdel(dest);
		return (-1);
	}
	ft_strdel(&dec);
	return (1);
}

static int	get_parts(t_vec *dest, long double val, t_stat *info)
{
	char		*whl;
	char		*dec;
	long double	d;

	whl = ft_anytoa((unsigned long ) val, 10, info->sign, false);
	if (!whl)
	{
		ft_vecdel(dest);
		return (-1);
	}
	d = (val - (unsigned long ) val) * ft_pow(10, info->preci);
	dec = ft_anytoa((unsigned long ) d, 10, 1, false);
	if (!dec)
	{
		ft_strdel(&whl);
		ft_vecdel(dest);
		return (-1);
	}
	return (add_parts(dest, whl, dec, info));
}

int	tc_dbl(t_vec *dest, t_stat *info)
{
	long double		val;
	t_vec			temp;

	if (info->lenght == L)
		val = va_arg(info->ap, long double);
	else
		val = va_arg(info->ap, double);
	info->sign = 1 - (2 * (val < 0));
	if (info->is_signed)
		val *= info->sign;
	info->preci = 6 * !info->preci_on + info->preci;
	val = round_dbl(val, info->preci);
	if (ft_vecnew(&temp, 1, sizeof(char)) < 0)
		return (-1);
	if (get_parts(&temp, val, info) < 0)
		return (-1);
	if (ft_vecappend(dest, &temp) < 0)
	{
		ft_vecdel(&temp);
		return (-1);
	}
	ft_vecdel(&temp);
	return (1);
}
