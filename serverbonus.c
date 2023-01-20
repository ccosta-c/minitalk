/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverbonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:39:14 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/01/19 13:49:54 by ccosta-c         ###   ########.fr       */
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
	if (argc != 1)
	{
		ft_printf("WROOOOOOONG!");	
	}		
	ft_printf("Server Started.\nThe PID is %d\n",getpid());
	while (1)
	{
		pause();
		signal(SIGUSR1, handler_server);
		signal(SIGUSR2, handler_server);
	}
	return (0);
}