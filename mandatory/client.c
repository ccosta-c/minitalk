/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:42:17 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/01/24 15:18:00 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	handler_client(char character, int pid)
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
		usleep(400);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 3)
		ft_printf("\033[1;31mThe command is ./client [PID] [MESSAGE]\033[0m\n");
	else
	{
		i = 0;
		while (argv[2][i] != '\0')
		{
			handler_client(argv[2][i], ft_atoi(argv[1]));
			i++;
		}
	}
	return (0);
}
