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

void	err_handle(t_err err)
{
	if (err == ERR_ALLOC)
	{
		ft_putstr_fd(RED "[ERROR]" END "Bad allocation \n", 2);
		exit(EXIT_FAILURE);
	}
	if (err == ERR_PID)
	{
		ft_putstr_fd(RED "[ERROR]" END "Please enter a valid PID \n", 2);
		exit(EXIT_FAILURE);
	}
	if (err == ERR_STR)
	{
		ft_putstr_fd("\e[1;31m[ERROR]\e[0m Please enter a valid string \n", 2);
		exit(EXIT_FAILURE);
	}
	if (err == ERR_ARG)
	{
		ft_putstr_fd("\e[1;31m[ERROR]\e[0m Wrong arguments! \n", 2);
		exit(EXIT_FAILURE);
	}
}
