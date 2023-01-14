/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:42:17 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/01/14 13:29:24 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void handler_client(unsigned char character, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((character & (0b1 << i)) == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
		usleep(25000);
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