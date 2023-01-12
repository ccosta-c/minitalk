/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:39:14 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/01/12 15:41:10 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void handler_server(int signal)
{
	static int	character;
	static char	i;

	i = 0;
	if (signal == SIGUSR1)
		character = character | (1 << i);
	if (i == 7)
		ft_printf("%c", character);
	i++;
}

int	main(int argc, char** argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf("WROOOOOOONG!");	
	}
	else
	{
		ft_printf("PID is %d\n",getpid());
		while (1)
		{
			signal(SIGUSR1, handler_server);
			signal(SIGUSR2, handler_server);
		}
	}
	return (0);
}