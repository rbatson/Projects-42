/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sems.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:41:50 by rbatson           #+#    #+#             */
/*   Updated: 2022/07/01 23:37:38 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

sem_t	*ft_sem_open(char const *name, int value)
{
	return (sem_open(name, O_CREAT | O_EXCL, 0644, value));
}

char	*make_semaphore_name(char const *base, char *buffer, int position)
{
	int	i;

	i = ft_strcpy(buffer, base);
	while (position > 0)
	{
		buffer[i++] = (position % 10) + '0';
		position /= 10;
	}
	buffer[i] = 0;
	return (buffer);
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
