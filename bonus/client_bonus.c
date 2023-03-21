/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:42:17 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/01/27 14:40:39 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_bonus.h"

void handler_client(char character, int pid)
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
		usleep(200);
	}
}

void	message_received(int signal, siginfo_t *info, void *ucontext)
{
	(void)signal;
	(void)info;
	(void)ucontext;
	printf("Message Received!\n");
}

int	main(int argc, char** argv)
{
	int	i;
	int server_pid;
	struct sigaction sms;
	if (argc != 3)
	{
		ft_printf("Wrong input, the command is ./client [PID] [MESSAGE].");	
	}
	else
	{
		i = 0;
		sms.sa_sigaction = &message_received;
		sms.sa_flags = SA_SIGINFO;
		server_pid = ft_atoi(argv[1]);
		if (sigaction(SIGUSR1, &sms, NULL) == -1)
			ft_printf("Error");
		while (argv[2][i] != '\0')
		{
			handler_client(argv[2][i], server_pid);
			i++;
		}
		handler_client('\n', server_pid);
		handler_client('\0', server_pid);
	}
	return (0);
}