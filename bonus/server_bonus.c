/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:39:14 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/01/27 11:43:53 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_bonus.h"

void handler_server(int signal, siginfo_t *info, void *ucontext)
{
	static unsigned char	character;
	static int				i;

	(void)ucontext;
	if (signal == SIGUSR1)
		character |= (0b1 << i);
	i++;
	if (i == 8)
	{
		if (character == '\0')
			kill(info->si_pid, SIGUSR1);
		write(1, &character, 1);
		i = 0;
		character = 0;
	}
}

int	main(int argc, char** argv)
{
	(void)argv;
	struct sigaction usr;
	usr.sa_sigaction = &handler_server;
	usr.sa_flags = SA_SIGINFO;

	if (argc != 1)
	{
		ft_printf("No arguments needed for this command.");	
	}		
	ft_printf("PID is %d.\n",getpid());
	sigaction(SIGUSR1, &usr, NULL);
	sigaction(SIGUSR2, &usr, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}