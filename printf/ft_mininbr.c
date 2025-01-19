/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:09:08 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/11/02 17:50:12 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_mininbr(int nb)
{
	int		len;
	char	*txt;

	len = 0;
	txt = ft_itoa(nb);
	if (!txt)
	{
		free(txt);
		return (0);
	}
	len = ft_strlen(txt);
	ft_ministr(txt);
	free(txt);
	return (len);
}
