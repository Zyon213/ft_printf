/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:02:16 by yonas             #+#    #+#             */
/*   Updated: 2021/11/14 02:36:34 by yonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int n)
{
	int 	len;
	int	nb;
	char	*str;

	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}

	if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}

	if (n < 0)
		nb = -n;
	else
		nb = n;
	len = ft_intlen(n);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (nb > 0)
	{
		str[len] = (nb % 10) + 48;
		nb /= 10;
		len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

char	*ft_itoau(unsigned int n)
{
	int		i;
	char		*str;
	unsigned int	nb;

	nb = n;
	if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	while (nb > 0)
	{
		str[i] = (nb % 10) + 48;
		nb /= 10;
		i--;
	}
	return (str);
}

char	*ft_convert_hex(size_t n) 
{
	int i;
	int j;
	char hex[42];
	char *hexa;
	char let[] = "0123456789abcdef";

	if (n == 0)
		return (NULL);
	hexa = malloc(43);
	if (hexa == NULL)
		return (NULL);
	i = 0;
	while (n != 0)
	{
		hex[i++] = let[(n % 16)];
		n = n / 16;
	}
	j = 0;
	while (i >= 0)
		hexa[j++] = hex[--i];
	hexa[j] = '\0';
	return (hexa);
}

char	*ft_convert_hexcap(size_t n)
{
	int	i;
	int	j;
	char	hexc[42];
	char	*hexa;
	char	let[] = "0123456789ABCDEF";

	if (n == 0)
		return (NULL);
	hexa = malloc(43);
	if (hexa == NULL)
		return (NULL);
	i = 0;
	while (n != 0)
	{
		hexc[i++] = let[(n % 16)];
		n /= 16;
	}
	j = 0;
	while (i >= 0)
		hexa[j++] = hexc[--i];
	hexa[j] = '\0';
	return (hexa);
}
