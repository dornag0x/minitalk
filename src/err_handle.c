/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <feufeuhugo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:59:32 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/17 14:11:15 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minitalk.h"

void	err_handle(int err)
{
	if (err == 0)
	{
		ft_printf("\e[1;31m[ERROR]\e[0m Bad allocation");
		exit(EXIT_FAILURE);
	}
	if (err == 1)
	{
		ft_printf("\e[1;31m[ERROR]\e[0m Please enter a valid PID");
		exit(EXIT_FAILURE);
	}
	if (err == 2)
	{
		ft_printf("\e[1;31m[ERROR]\e[0m Please enter a valid string");
		exit(EXIT_FAILURE);
	}
	if (err == 3)
	{
		ft_printf("\e[1;31m[ERROR]\e[0m Wrong arguments!");
		exit(EXIT_FAILURE);
	}
}
