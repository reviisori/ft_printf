/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_dbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 23:27:56 by altikka           #+#    #+#             */
/*   Updated: 2022/05/25 13:53:50 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static long double	ft_powl(long double x, long double y)
{
	long double		n;

	n = 1;
	while (y-- > 0)
		n *= x;
	return (n);
}

long double	round_dbl(long double val, unsigned int preci)
{
	long double		temp;
	long double		pow;
	unsigned int	i;
	unsigned long	whl;

	pow = ft_powl(0.1, preci);
	temp = val;
	i = 0;
	while (i++ < preci)
	{
		whl = temp;
		temp -= whl;
		temp *= 10;
	}
	temp -= whl;
	if (temp == 0.5)
	{
		if (whl % 2 != 0)
			val = val + pow - (pow / 10);
	}
	else if (temp > 0.5)
		val = val + pow - (pow * 0.1);
	return (val);
}

long double	round_dbl_v2_old(long double val, unsigned int preci)
{
	long double		pow;
	long double		dec;
	unsigned int	mdl;

	pow = (long double ) ft_pow(10, preci);
	dec = val * pow * 10;
	mdl = (unsigned long ) dec % 10;
	if (((val - (unsigned long ) val) / pow) == 0.5)
	{
		if ((unsigned long )(dec / 10) % 2 != 0)
			dec = (dec / 10) + 1 - 0.1;
		else
			dec /= 10;
	}
	else if (mdl >= 5)
	{
		dec = (dec / 10) + 1 - 0.1;
		if ((unsigned int ) ft_anylen(dec, 10, 1) > preci + 1)
			return ((long double )((int )(val + 0.5)));
	}
	else
		dec /= 10;
	return (dec / pow);
}
