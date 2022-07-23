/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:23:29 by rbatson           #+#    #+#             */
/*   Updated: 2021/10/26 17:43:01 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr_len(int n)
{
	int		d;

	d = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		d++;
	}
	return (d);
}

static char	*ft_int_plus(int n, int len)
{
	char	*ss;

	ss = (char *)malloc(sizeof(*ss) * (len + 1));
	if (ss)
	{
		ss[len] = '\0';
		len--;
		while (len >= 0)
		{
			ss[len] = ((n % 10) + '0');
			n = n / 10;
			len--;
		}
		return (ss);
	}
	return (0);
}

static char	*ft_int_minus(int n, int len)
{
	char	*ss;

	ss = (char *)malloc(sizeof(*ss) * (len + 2));
	if (ss)
	{
		len++;
		ss[len] = '\0';
		len--;
		ss[0] = '-';
		while (len > 0)
		{
			ss[len] = ((n % 10) + '0');
			n = n / 10;
			len--;
		}
		return (ss);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	char	*ss;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_nbr_len(n);
	if (n >= 0)
		return (ss = ft_int_plus(n, len));
	return (ss = ft_int_minus((n * -1), len));
}
