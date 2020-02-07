/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printconv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:06:07 by smaccary          #+#    #+#             */
/*   Updated: 2020/02/05 21:10:27 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

static int	print_p(void *ptr, t_infos infos)
{
	infos.printer(1, "0x", 2);
	return (ft_putnbr_base_u((size_t)ptr, HEX_BASE_LOW, ptr) + 2);
}

static int	print_s(char *str, t_infos infos)
{
	return ((str) ? infos.printer(1, str, ft_strlen(str)) :
	 infos.printer(1, str, ft_strlen(str)));
}

static int	print_conv_2(char c, va_list *list, t_infos infos)
{
	int printed;

	printed = 0;
	if (c == 'p')
		printed += print_p((void *)va_arg(*list, void *), infos);
	if (c == 'd' || c == 'i')
		printed += ft_putnbr_base_int(va_arg(*list, int), DEC_BASE, infos.printer);
	else if (c == 'u')
		printed += ft_putnbr_base_u(
			(size_t)va_arg(*list, size_t), DEC_BASE, infos.printer);
	else if (c == 'x')
		printed += ft_putnbr_base_u(
			(size_t)va_arg(*list, size_t), HEX_BASE_LOW, infos.printer);
	else if (c == 'X')
		printed += ft_putnbr_base_u(
			(size_t)va_arg(*list, size_t), HEX_BASE_UP, infos.printer);
	return (printed);
}

int			print_conv(t_infos infos, va_list *list)
{
	if (infos.conv == 'c')
		return (infos.printer(1, infos.conv, 1));
	else if (infos.conv == 's')
		return (print_s((char *)va_arg(*list, char *), infos));
	else if (infos.conv == '%')
		return (infos.printer(1, "%", 1));
	else if (ft_strchr("pdiuxX", infos.conv))
		return (print_conv_2(infos.conv, list, infos));
}
