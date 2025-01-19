/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <feufeuhugo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:59:41 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/17 14:24:14 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H

#include <stdlib.h>
#include <signal.h>
#include "../libft/libft.h"
#include "../printf/ft_printf.h" 

typedef struct s_data
{
	int		s_PID;
	char	*msg;
}	t_data;

void	err_handle(int err);
#endif
