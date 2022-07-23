/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 18:44:37 by rbatson           #+#    #+#             */
/*   Updated: 2022/01/06 19:18:07 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int nb)
{
	int	res;

	res = 0;
	if (nb >= 10)
	{
		res += ft_putunsigned(nb / 10);
		res += ft_putunsigned(nb % 10);
	}
	if (nb < 10)
		res += ft_putchar(nb + 48);
	return (res);
}

int	ft_whatsymb(char c, va_list *va)
{
	int	res;

	res = 0;
	if (c == 'c')
		res += ft_putchar(va_arg(*va, int));
	if (c == 's')
		res += ft_putstr(va_arg(*va, char *));
	if (c == 'p')
	{
		res += write(1, "0x", 2);
		res += ft_putaddress(va_arg(*va, unsigned long int));
	}
	if (c == 'd' || c == 'i')
		res += ft_putnbr(va_arg(*va, unsigned int));
	if (c == 'u')
		res += ft_putunsigned(va_arg(*va, unsigned int));
	if (c == 'x')
		res += ft_puthexadecimal(va_arg(*va, unsigned int), 1);
	if (c == 'X')
		res += ft_puthexadecimal(va_arg(*va, unsigned int), 2);
	if (c == '%')
		res += write (1, "%", 1);
	return (res);
}

int	ft_printf(const char *string, ...)
{
	int		res;
	int		i;
	va_list	va;

	res = 0;
	i = 0;
	va_start(va, string);
	while (string[i])
	{
		if (string[i] != '%')
			res += write(1, &string[i], 1);
		if (string[i] == '%')
		{
			res += ft_whatsymb(string[i + 1], &va);
			i++;
		}
		i++;
	}
	va_end(va);
	return (res);
}
