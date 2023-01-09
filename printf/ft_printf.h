/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:31:09 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/01/05 13:43:05 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_integer(long nb);
int	ft_char(char x);
int	ft_hex(unsigned long nb, char c);
int	ft_string(char *str);
int	ft_unsigned(unsigned int nb);
int	ft_adress(unsigned long adress);

#endif