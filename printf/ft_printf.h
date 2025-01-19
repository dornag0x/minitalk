/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:13:53 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/11/02 17:26:08 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int		printperc(void);
int		ft_putcharo(char c);
int		ft_select(char c, va_list args);
int		ft_printf(const char *str, ...);
void	ft_puthexa(unsigned int nb, char c);
int		ft_uputnbr(unsigned int nb);
int		ft_ministr(char *s);
int		ft_hexa(unsigned int nb, char c);
int		lencalc(unsigned int nb);
int		ft_mininbr(int nb);
int		ft_pointprint(void *p);
#endif
