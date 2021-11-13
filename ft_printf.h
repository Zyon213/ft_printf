/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:59:35 by yonas             #+#    #+#             */
/*   Updated: 2021/11/14 01:58:04 by yonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H


#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

char	*ft_itoa(int n);
char	*ft_itoau(unsigned int n);
char	*ft_convert_hex(size_t n);
char	*ft_convert_hexcap(size_t n);
size_t	ft_intlen(int n);
size_t	ft_strlen(char *str);
void	ft_putstr(char *str);
char	*ft_strcpy(char *dup, char *str);
char	*ft_strdup(char *str);
int	ft_print_format(char format, va_list arg);
int	ft_printf(char const *s, ...);
int	ft_printchar(va_list arg);
int	ft_printstr(va_list arg);
int	ft_printunsignint(va_list arg);
int	ft_printinteger(va_list arg);
int	ft_printvoid(va_list arg);
int	ft_printhex(va_list arg);
int	ft_printcaphex(va_list arg);
int	ft_putchar(char c);
void	ft_putstr(char *str);
int	ft_nbrlen_base(size_t n);

#endif
