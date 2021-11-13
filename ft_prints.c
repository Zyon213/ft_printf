/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:09:30 by yonas             #+#    #+#             */
/*   Updated: 2021/11/14 02:29:26 by yonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (c)
		write(1, &c, 1);
	return (1);
}

int	ft_printchar(va_list arg)
{
	char	c;

	c = va_arg(arg, int);
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(va_list arg)
{
	char	*str;

	str = va_arg(arg, char*);
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(str);
	return (ft_strlen(str));
}

int	ft_printunsignint(va_list arg)
{
	unsigned int	nb;
	char		*str;
	int		len;

	nb = va_arg(arg, unsigned int);
	str = ft_itoau(nb);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}

int	ft_printinteger(va_list arg)
{
	char	*str;
	int	len;
	int	n;

	n = va_arg(arg, int);
	str = ft_itoa(n);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}

int	ft_printvoid(va_list arg)
{
	size_t	nb;
	char		*str;
	int		len;

	nb = (size_t )va_arg(arg, void *);
	len = ft_nbrlen_base(nb);
	str = ft_convert_hex(nb);
	if (str == NULL)
	{
		ft_putstr("(nil)");
		return (5);
	}
	ft_putstr("0x");
	ft_putstr(str);
	free(str);
	return (len + 2);
}

int	ft_printhex(va_list arg)
{
	unsigned int nb;
	int		len;
	char		*str;

	nb = va_arg(arg, unsigned int);
	len = ft_nbrlen_base(nb);
	str = ft_convert_hex(nb);
	if (str == NULL)
	{
		ft_putstr("0");
		return (1);
	}
	ft_putstr(str);
	free(str);
	return (len);
}

int	ft_printcaphex(va_list arg)
{
	unsigned int	nb;
	int		len;
	char		*str;

	nb = va_arg(arg, unsigned int);
	len = ft_nbrlen_base(nb);
	str = ft_convert_hexcap(nb);
	if (str == NULL)
	{
		ft_putstr("0");
		return (1);
	}
	ft_putstr(str);
	free(str);
	return (len);
}
