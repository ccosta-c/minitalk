/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:39:14 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/01/24 15:18:32 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	handler_server(int signal)
{
	static unsigned char	character;
	static int				i;

	if (signal == SIGUSR1)
		character |= (0b1 << i);
	i++;
	if (i == 8)
	{
		write(1, &character, 1);
		i = 0;
		character = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	usr;

	(void)argv;
	usr.sa_handler = &handler_server;
	if (argc != 1)
		ft_printf("\033[1;31mNo arguments needed.\033[0m\n");
	ft_printf("PID is %d\n", getpid());
	sigaction(SIGUSR1, &usr, NULL);
	sigaction(SIGUSR2, &usr, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
