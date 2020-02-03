/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenconv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:10:30 by smaccary          #+#    #+#             */
/*   Updated: 2020/01/31 08:23:03 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

static int	len_p(void *ptr)
{
	return (len_nbr_base_u((unsigned int)ptr, HEX_BASE_LOW) + 2);
}

static int	len_s(char *str)
{
	return ((str) ? ft_strlen(str) : 6);
}

static int	len_conv_2(char c, va_list copy)
{
	int printed;

	printed = 0;
	if (c == 'p')
		printed += len_p((void *)va_arg(copy, void *));
	if (c == 'd' || c == 'i')
		printed += len_nbr_base_int((int)va_arg(copy, int), DEC_BASE);
	else if (c == 'u')
		printed += len_nbr_base_u(
			(unsigned int)va_arg(copy, size_t), DEC_BASE);
	else if (c == 'x')
		printed += len_nbr_base_u(
			(unsigned int)va_arg(copy, size_t), HEX_BASE_LOW);
	else if (c == 'X')
		printed += len_nbr_base_u(
			(unsigned int)va_arg(copy, size_t), HEX_BASE_UP);
	return (printed);
}

int			len_conv(char c, va_list *list)
{
	int		printed;
	va_list	copy;

	va_copy(copy, *list);
	printed = 0;
	if (!c)
		return (0);
	if (c == 'c')
		++printed;
	else if (c == 's')
		printed += len_s((char *)va_arg(*list, char *));
	else if (c == '%')
		++printed;
	else if (ft_strchr("pdiuxX", c))
		printed += len_conv_2(c, list);
	va_end(copy);
	return (printed);
}
