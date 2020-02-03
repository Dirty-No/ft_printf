/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 00:15:48 by smaccary          #+#    #+#             */
/*   Updated: 2020/02/03 19:33:12 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <stdlib.h>
#include "libftprintf.h"

size_t		no_write(int filedes, const void *buf, size_t nbyte)
{
	(void)filedes;
	(void)buf;
	return (nbyte)
}

static int	print_to_flag(char **str,
	   	size_t (*my_write)(int, const void *, size_t))
{
	int i;

	i = 0;
	while ((*str)[i] && (*str)[i] != '%')
		i++;
	if ((*str)[i + 1] == '%')
	{
		i++;
		my_write(1, *str, i);
		*str += i + 1;
		return (i + print_to_flag(str));
	}
	else if (i)
		my_write(1, *str, i);
	*str += i;
	return (i);
}

int			 ft_vprintf((*my_write)(int, const void *, size_t), const char *format, va_list *list)
{
	int		printed;
	char	*str;

	if (!format || !(str = ft_strdup(format)))
		return (my_write(1, "(null)", 6));
	printed = 0;
	while (*str)
	{
		printed += print_to_flag(&str);
		str = get_conv(str);
		printed += (*str) ? print_form(str, list) : 0;
	}
	va_end(*list);
	free(str);
	return (printed);
}

int			ft_printf(const char *format, ...)
{
	va_list	list;

	va_start(list, format);
	return (ft_vprintf(write, format, &list));
}
