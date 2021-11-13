/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:05:19 by yonas             #+#    #+#             */
/*   Updated: 2021/11/13 18:43:38 by yonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_intlen(int n)
{
	size_t	i;
	int	nb;
	
	nb = n;
	if (n == 0)
		return (1);
	if (nb < 0)
		nb = -nb;
	i = 0;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	if (n < 0)
		return (i + 1);
	else
		return (i);
}

int	ft_nbrlen_base(size_t n)
{
	int len;

	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*ft_strcpy(char *dup, char *str)
{
	while ((*dup++ = *str++))
		;
	return (dup);
}
char	*ft_strdup(char *str)
{
	char	*dups;

	dups = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (dups != NULL)
		ft_strcpy(dups, str);
	return (dups);
}
