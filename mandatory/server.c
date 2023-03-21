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

void handler_server(int signal)
{
	static unsigned char	character;
	static int				i;

	if (signal == SIGUSR1)
		character |= (0b1 << i);
	i++;
	if (i == 8)
	{
		ft_printf("%c", character);
		i = 0;
		character = 0;
	}
}

int	main(int argc, char** argv)
{
	(void)argv;
	struct sigaction usr;
	usr.sa_handler = &handler_server;

	if (argc != 1)
	{
		ft_printf("No arguments needed.");	
	}		
	ft_printf("PID is %d\n",getpid());
	sigaction(SIGUSR1, &usr, NULL);
	sigaction(SIGUSR2, &usr, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}