/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:41:59 by rbatson           #+#    #+#             */
/*   Updated: 2022/07/01 23:37:47 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	register const char	*str;

	str = s;
	while (*s)
		++s;
	return (s - str);
}

static int	ft_sub_atoi(const char *str, int i, int sign)
{
	int	dig;
	int	tens;
	int	res;

	res = 0;
	dig = 0;
	tens = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		dig++;
		i++;
	}
	if ((dig > 10) && (sign == 1))
		return (-1);
	if ((dig > 10) && (sign == -1))
		return (0);
	i--;
	while (dig != 0)
	{
		res = res + (str[i] - 48) * tens;
		tens = tens * 10;
		dig--;
		i--;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		sign = sign * -1;
	}
	res = ft_sub_atoi(str, i, sign);
	return (res * sign);
}

void	ft_putnbr_fd(unsigned long long n, int fd)
{
	char	str[13];
	int		length;

	if (n == 0)
		str[0] = '0';
	length = 0;
	while (n != 0)
	{
		str[length++] = '0' + (n % 10);
		n = (n / 10);
	}
	if (length > 0)
		length--;
	while (length >= 0)
		write(fd, &str[length--], 1);
}

unsigned long long	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (unsigned long long)1000) + (tv.tv_usec / 1000));
}
