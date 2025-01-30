/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <feufeuhugo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:59:41 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/30 13:13:32 by hfeufeu          ###   ########.fr       */
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

typedef struct s_node
{
    char            c;
    struct s_node   *next;
}   t_node;

typedef struct s_lst
{
    t_node  *head;
    t_node  *tail;
}   t_lst;

void	free_list(t_lst *list);
char	*list_to_string(t_lst *list);
t_lst	*init_list();
void	append_char(t_lst *list, char letter);
void	err_handle(int err);
#endif
