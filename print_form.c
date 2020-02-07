/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaccary <smaccary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 04:00:46 by smaccary          #+#    #+#             */
/*   Updated: 2020/02/05 20:44:40 by smaccary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	print_form(const char *format, va_list *list, ssize_t (*my_write)(int, const void *, size_t))
{
	char	*str;
	int		count;
	t_infos infos;

	if (!(str = ft_substr(format, 0, get_conv((char *)format) + 1 - format)))
		return (my_write(1, "ERROR", 5));
	count = 0;
	infos = get_infos(str, list, (*my_write));

	//printf("'%c' %d %d '%c' '%c'", infos.space, infos.width, infos.precision,
	//	   	infos.pos, infos.conv);
	if (!(infos.width && infos.precision))
		print_conv(infos);

	free(str);
	return (count);
}
