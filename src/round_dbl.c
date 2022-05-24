/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round_dbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 23:27:56 by altikka           #+#    #+#             */
/*   Updated: 2022/05/24 18:15:50 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*	while (i++ < preci)
	{
		temp = val;
		val -= temp;
		val *= 10;
	}
	val -= temp;
*/

long double	round_dbl(long double val, unsigned int preci)
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
