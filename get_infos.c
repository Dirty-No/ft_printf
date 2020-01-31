/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 05:10:23 by smaccary          #+#    #+#             */
/*   Updated: 2020/01/31 06:03:54 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

static int get_width(char *format, va_list *list)
{
	return ((*format == '*') ? va_arg(*list, int) : ft_atoi(format));
}

static int	get_precision(char *format, va_list *list)
{
	return ((format = ft_strchr(format, '.')) ? ft_atoi(format) : 0);
}

t_infos		get_infos(char *format, va_list *list)
{
	t_infos	infos;

	if (*format == '-')
	{
		infos.pos = 'l';
		format++;
	}
	else
		infos.pos = 'r';
	if (*format == '0')
	{
		infos.space = '0';
		format++;
	}
	else
		infos.space = ' ';
	infos.width = get_width(format, list);
	infos.precision = get_precision(format, list);
	return (infos);
}
