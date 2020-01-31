/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 00:15:48 by smaccary          #+#    #+#             */
/*   Updated: 2020/01/31 03:38:22 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"

int ft_printf(const char *format, ...)
{
	int		printed;
	char	*str;
	va_list	list;

	if (!format || !(str = ft_strdup(format)))
		return (write(1, "(null)", 6));
	printed = 0;
	va_start(list);
	while (*str)
	{
		printed += print_to_flag(&str);
		str = get_conv(str);
		printed += (*str) ? print_form(str, &list) : 0;
	}
	va_end(list);
	free(str);
	return (ret);
}
