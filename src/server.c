/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <feufeuhugo@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:46:24 by hfeufeu           #+#    #+#             */
/*   Updated: 2025/01/17 13:57:39 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minitalk.h"

void	append_char(char **str, char letter)
{
	char	*new_str;
	size_t	len;

	if (!*str)
		*str = ft_strdup("");
	len = ft_strlen(*str);
	new_str = malloc(len + 2);
	if (!new_str)
		err_handle(0);
	ft_memcpy(new_str, *str, len);
	new_str[len] = letter;
	new_str[len + 1] = '\0';
	free(*str);
	*str = new_str;
}

void	handler(int signals)
{
	static int	counter = 0;
	static int	result = 0;
	static char	*final = NULL;

	if (signals == SIGUSR2)
		result |= (1 << (7 - counter));
	counter++;
	if (counter == 8)
	{
		append_char(&final, result);
		if (result == '\0')
		{
			ft_printf("%s\n", final);
			free(final);
			final = NULL;
		}
		counter = 0;
		result = 0;
	}
}

int	main()
{
	struct sigaction	act;

	ft_printf("%d\n", getpid());
	act.sa_handler = handler;
	act.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
}
