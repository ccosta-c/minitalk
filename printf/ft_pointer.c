/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:33:23 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/01/05 14:08:11 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_adress(unsigned long adress)
{
	int	count;

	if (!adress)
		return (ft_string("(nil)"));
	count = 0;
	count += ft_string("0x");
	count += ft_hex(adress, 'x');
	return (count);
}
