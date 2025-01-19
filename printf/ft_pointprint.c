/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:28:28 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/11/02 17:30:19 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printhex(unsigned long nb)
{
	char	*base;
	int		val;

	base = "0123456789abcdef";
	val = 0;
	if (nb >= 16)
		val += ft_printhex(nb / 16);
	write(1, &base[nb % 16], 1);
	return (val + 1);
}

int	ft_pointprint(void *p)
{
	unsigned long	addr;
	int				val;

	addr = (unsigned long)p;
	if (addr == 0 || !p)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	val = ft_printhex(addr);
	return (val + 2);
}
