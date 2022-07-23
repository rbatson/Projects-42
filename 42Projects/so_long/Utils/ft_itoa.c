/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:42:50 by rbatson           #+#    #+#             */
/*   Updated: 2022/05/28 22:44:49 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

unsigned int	ft_count(long per, int znak)
{
	unsigned int	schet;

	schet = 0;
	if (per == 0)
		return (1);
	while (per > 0)
	{
		per = per / 10;
		schet++;
	}
	if (znak == -1)
		schet++;
	return (schet);
}

void	ft_conv(char *out, long per, int znak, unsigned int schet)
{
	out[schet] = '\0';
	out[--schet] = per % 10 + '0';
	per = per / 10;
	while (per > 0)
	{
		out[--schet] = per % 10 + '0';
		per = per / 10;
	}
	if (znak == -1)
		out[0] = '-';
}

char	*ft_itoa(int n)
{
	int				znak;
	long			per;
	unsigned int	schet;
	char			*out;

	znak = 1;
	if (n < 0)
	{
		per = (long)n * -1;
		znak = -1;
	}
	else
		per = (long)n;
	schet = ft_count(per, znak);
	out = (char *)malloc(schet + 1);
	if (!out)
		return (NULL);
	ft_conv(out, per, znak, schet);
	return (out);
}
