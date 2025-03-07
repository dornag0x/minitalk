/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <feufeuhugo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:08:33 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/02/01 10:00:00 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	get_lenght(t_lst *lst)
{
	int		i;
	t_node	*cpy;

	i = 0;
	cpy = lst->head;
	while (cpy != NULL)
	{
		i++;
		cpy = cpy->next;
	}
	return (i);
}

t_lst	*init_list(void)
{
	t_lst	*list;

	list = malloc(sizeof(t_lst));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	return (list);
}

void	free_list(t_lst *list)
{
	t_node	*tmp;

	while (list->head != NULL)
	{
		tmp = list->head;
		list->head = list->head->next;
		free(tmp);
	}
	free(list);
}
