/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpfull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:59:50 by rbatson           #+#    #+#             */
/*   Updated: 2022/01/06 19:53:42 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char ch)
{
	int	i;

	i = write (1, &ch, 1);
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (*str)
		i += write (1, str++, 1);
	return (i);
}

int	ft_putnbr(int num)
{
	long long	n;
	int			i;

	n = num;
	i = 0;
	if (n < 0)
	{
		i += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	if (n < 10)
		i += ft_putchar (n + 48);
	return (i);
}

int	ft_puthexadecimal(unsigned int nb, int s)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_puthexadecimal(nb / 16, s);
		len += ft_puthexadecimal(nb % 16, s);
	}
	if (nb < 16)
	{
		if (nb < 10)
			len += ft_putchar(nb + 48);
		else
		{
			if (s == 1)
				len += ft_putchar(nb + 87);
			else
				len += ft_putchar(nb + 55);
		}
	}
	return (len);
}

int	ft_putaddress(unsigned long int nb)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_putaddress(nb / 16);
		len += ft_putaddress(nb % 16);
	}
	if (nb < 16)
	{
		if (nb < 10)
			len += ft_putchar(nb + 48);
		else
			len += ft_putchar(nb + 87);
	}
	return (len);
}
