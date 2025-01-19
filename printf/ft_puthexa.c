/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:02:33 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/11/02 17:50:22 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_puthexa(unsigned int nb, char c)
{
	if (nb >= 16)
	{
		ft_puthexa((nb / 16), c);
		ft_puthexa((nb % 16), c);
	}
	else if (nb <= 9)
		ft_putcharo(nb + '0');
	else
	{
		if (c == 'x')
			ft_putcharo((nb - 10) + 'a');
		if (c == 'X')
			ft_putcharo((nb - 10) + 'A');
	}
}

int	lencalc(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

int	ft_hexa(unsigned int nb, char c)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	else
		ft_puthexa(nb, c);
	i = lencalc(nb);
	return (i);
}
