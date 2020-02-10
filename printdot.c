/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 08:59:34 by smaccary          #+#    #+#             */
/*   Updated: 2020/02/08 19:17:41 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
static int wrap_print_flag(char *format , ...)
{
	va_list lst;
	int		count;

	va_start(lst, format);
	count = print_flag(&format, &lst);
	va_end(lst);
	return (count);
}
*/

static int print_dot_int(t_infos *infos, va_list *list)
{
	int		count;
	int		arg;

	count = 0;
	arg = (int)va_arg(*list, int);
	count = (arg < 0) ? wp_ft_vprintf("-%0*d", infos->printer, infos->precision, arg * -1) :
	ft_vprintf("%0*d", infos->precision, arg);
	infos->precision = (arg < 0) ? infos->precision + 1 : infos->precision;
	return (count);
}

int	print_dot(t_infos *infos, va_list *list)
{
	char *str;

	if (infos->conv == 'c')
		return (ft_printf("%0*c", infos->precision, (char)va_arg(*list, int)));
	if (infos->conv == 's')
	{
		str = (char *)va_arg(*list, char *);
		return (write(1, str, (infos->precision <= (int)ft_strlen(str)) ? infos->precision : ft_strlen(str)));
	}
	if (infos->conv == 'p')
		return (ft_printf("%0*p", infos->precision, (unsigned int)va_arg(*list, unsigned int)));
	if (infos->conv == 'd' || infos->conv == 'i')
		return (print_dot_int(infos, list));
		//return (ft_printf("%0*d", infos->precision, (int)va_arg(*list, int)));
	if (infos->conv == 'u')
		return (ft_printf("%0*u", infos->precision, va_arg(*list, unsigned int)));
	if (infos->conv == 'x')	
		return (ft_printf("%0*x", infos->precision, va_arg(*list, unsigned int)));
	if (infos->conv == 'X')
		return (ft_printf("%0*X", va_arg(*list, unsigned int)));
	return (0);
}
/*
static int wrap_len_flag(char *format , ...)
{
	va_list lst;
	int		count;

	va_start(lst, format);
	count = len_flag(format, &lst);
	va_end(lst);
	return (count);
}
*/