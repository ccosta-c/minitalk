/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientbonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:42:17 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/01/19 13:49:05 by ccosta-c         ###   ########.fr       */
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
		{
			kill(pid, SIGUSR2);
		}
		else
		{
			kill(pid, SIGUSR1);
		}
		i++;
		usleep(250);
	}
}

int	main(int argc, char** argv)
{
	int	i;
	int pid;

	pid = ft_atoi(argv[1]);
	i = 0;
	if (argc != 3)
	{
		ft_printf("Wrong input, the command is './client [PID] [MESSAGE]'");	
	}
	else
	{
		while (argv[2][i] != '\0')
		{
			handler_client((unsigned char)argv[2][i], pid);
			i++;
		}
	}
	return (0);
}