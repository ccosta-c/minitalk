/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:42:17 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/01/12 15:38:37 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void handler_client(unsigned char character, int pid)
{
	char	i;

	i = 0;
	while (i < 8)
	{
		if ((character & (1 << i)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(200);
	}
}

int	main(int argc, char** argv)
{
	int	i;
	int pid;

	pid = atoi(argv[2]);
	i = 0;
	if (argc != 3)
	{
		ft_printf("WROOOOOOONG!\nTry ./server [MESSAGE] [PID]");	
	}
	else
	{
		while (argv[1][i] != '\0')
		{
			handler_client(argv[1][i], pid);
			i++;
		}
	}
	return (0);
}