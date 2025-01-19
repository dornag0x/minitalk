/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:43:56 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/11/02 17:58:16 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	printperc(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_putcharo(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_select(char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putcharo(va_arg(args, int));
	else if (c == 's')
		i += ft_ministr(va_arg(args, char *));
	else if (c == 'p')
		i += ft_pointprint(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		i += ft_mininbr(va_arg(args, int));
	else if (c == 'u')
		i += ft_uputnbr(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		i += ft_hexa(va_arg(args, unsigned int), c);
	else if (c == '%')
		i += printperc();
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		size;

	size = 0;
	i = 0;
	if (str[i] == '%' && str[i + 1] == '\0')
		return (-1);
	va_start(args, str);
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			size += ft_select(str[i + 1], args);
			i++;
		}
		else
			size += ft_putcharo(str[i]);
		i++;
	}
	va_end(args);
	return (size);
}
