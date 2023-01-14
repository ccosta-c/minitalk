/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:39:14 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/01/14 13:25:35 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void handler_server(int signal)
{
	static char	character;
	static int	i;

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
	if (argc != 1)
	{
		ft_printf("WROOOOOOONG!");	
	}		
	ft_printf("PID is %d\n",getpid());
	signal(SIGUSR1, handler_server);
	signal(SIGUSR2, handler_server);
	while (1)
	{
		pause();
	}
	return (0);
}