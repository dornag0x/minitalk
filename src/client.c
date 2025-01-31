/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <feufeuhugo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:57:42 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/30 13:53:01 by hfeufeu          ###   ########.fr       */
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
			usleep(SLEEP);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 8)
	{
		kill(s_PID, SIGUSR1);
		usleep(SLEEP);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 3)
	{
		data.pid = ft_atoi(argv[1]);
		if (data.pid < 1)
			err_handle(ERR_PID);
		data.msg = argv[2];
		if (!data.msg)
			err_handle(ERR_STR);
		sigsend(data.pid, data.msg);
	}
	else
		err_handle(ERR_ARG);
	return (0);
}
