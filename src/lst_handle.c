/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <feufeuhugo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:08:33 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/30 13:56:46 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minitalk.h"

t_lst *init_list()
{
    t_lst *list;

	list = malloc(sizeof(t_lst));
    if (!list)
        return (NULL);
    list->head = NULL;
    list->tail = NULL;
    return (list);
}

char *list_to_string(t_lst *list)
{
	int		i;
	char	*res;

	i = 0;
	while (list)
	{

	}
}

void free_list(t_lst *list)
{
	t_node *tmp;
	while (list->head)
	{
		tmp = list->head;
		list->head = list->head->next;
		free(tmp);
	}
	free(list);
}
