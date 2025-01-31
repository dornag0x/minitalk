/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <feufeuhugo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:46:24 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/30 13:54:27 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minitalk.h"

void append_char(t_lst *list, char letter)
{
	t_node *new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		err_handle(ERR_ALLOC);
	new_node->c = letter;
	new_node->next = NULL;
	if (!list->head)
		list->head = new_node;
	else
		list->tail->next = new_node;
	list->tail = new_node;
}

void	print_lst(t_lst *final)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = final->head;
	while (tmp)
	{
		write(1, &tmp->c, 1);
		tmp = tmp->next;
	}
}

void	handler(int signals)
{
	static int		counter = 0;
	static int		result = 0;
	static t_lst	*final = NULL;
	//char			*msg;

	if (!final)
		final = init_list();
	if (signals == SIGUSR2)
		result |= (1 << (7 - counter));
	counter++;
	if (counter == 8)
	{
		append_char(final, result);
		if (result == '\0')
		{
			print_lst(final);
			free_list(final);
			final = NULL;
		}
		counter = 0;
		result = 0;
	}
}


int	main(void)
{
	struct sigaction sa;

	ft_printf("server PID: \e[1;32m[%d]\e[0m \n", getpid());
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_handler = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
