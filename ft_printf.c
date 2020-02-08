/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 00:15:48 by smaccary          #+#    #+#             */
/*   Updated: 2020/02/08 01:25:18 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

ssize_t		no_write(int filedes, const void *buf, size_t nbyte)
{
	(void)filedes;
	(void)buf;
	return (nbyte);
}

int			my_putchar(char c, ssize_t (*my_write)(int, const void *, size_t))
{
	return((*my_write)(1, &c, 1));
}

static int	print_to_flag(char **str, ssize_t (*my_write)(int, const void *, size_t))
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
		return (i + print_to_flag(str, (*my_write)));
	}
	else if (i)
		my_write(1, *str, i);
	*str += i;
	return (i);
}

int			 ft_vprintf(const char *format, va_list *list, ssize_t (*my_write)(int, const void *, size_t))
{
	int		printed;
	char	*buffer;
	char	*str;

	if (!format || !(buffer = ft_strdup(format)))
		return (my_write(1, "(null)", 6));
	printed = 0;
	str = buffer;
	while (str && *str)
	{
		printed += print_to_flag(&str, (*my_write));
		printed += (str && *str) ? print_form(str, list, (*my_write)) : 0;
		str = get_conv(str) + 1;
	}
	va_end(*list);
	free(buffer);	
	return (printed);
}

int			ft_printf(const char *format, ...)
{
	va_list	list;

	if (!format)
		return (write(1, "(null)", 6));
	va_start(list, format);
	return (ft_vprintf(format, &list, write));
}
