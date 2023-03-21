/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:40:20 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/01/27 13:50:43 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H_BONUS
# define LIB_H_BONUS

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include "../libft/libft.h"

void	handler_client(char character, int pid);
void	handler_server(int signal, siginfo_t *info, void *ucontext);
void	message_received(int signal, siginfo_t *info, void *ucontext);

#endif
