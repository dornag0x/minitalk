/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <feufeuhugo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:57:42 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/17 14:24:14 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minitalk.h"

void	sigsend(int s_PID, char *msg)
{
	int	i;
	int	j;

	i = 0;
	while (msg[i])
	{
		j = 0;
		while (j < 8)
		{
			if (((unsigned int)(msg[i] >> (7 - j)) & 1) == 0)
				kill(s_PID, SIGUSR1);
			if (((unsigned int)(msg[i] >> (7 - j)) & 1) == 1)
				kill(s_PID, SIGUSR2);
			usleep(55);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 8)
	{
		kill(s_PID, SIGUSR1);
		usleep(55);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 3)
	{
		data.s_PID = ft_atoi(argv[1]);
		if (!data.s_PID)
			err_handle(1);
		data.msg = argv[2];
		if (!data.msg)
			err_handle(2);
		sigsend(data.s_PID, data.msg);
	}
	else
		err_handle(3);
	return (0);
}
