/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:08:11 by yonas             #+#    #+#             */
/*   Updated: 2021/11/13 18:09:17 by yonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(char format, va_list arg)
{
	if (format == 'c')
		return (ft_printchar(arg));
	else if (format == 's')
		return (ft_printstr(arg));
	else if (format == 'p')
		return (ft_printvoid(arg));
	else if (format == 'i' || format == 'd')
		return (ft_printinteger(arg));
	else if (format == 'u')
		return (ft_printunsignint(arg));
	else if (format == 'x')
		return (ft_printhex(arg));
	else if (format == 'X')
		return (ft_printcaphex(arg));
	else if (format == '%')
		return (ft_putchar(format));
	return (0);
}

int	ft_printf(char	const *s, ...)
{
	int	i;
	int	len;
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			len += ft_print_format(s[i + 1], arg);
			i++;
		}
		else if (s[i] != '%')
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
