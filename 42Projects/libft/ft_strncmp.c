/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:40:41 by rbatson           #+#    #+#             */
/*   Updated: 2021/10/26 16:36:01 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	i;
	unsigned char	*str11;
	unsigned char	*str22;

	str11 = (unsigned char *)str1;
	str22 = (unsigned char *)str2;
	i = 0;
	while (str1[i] && str2[i] && i < n)
	{
		if (str1[i] != str2[i])
			return (str11[i] - str22[i]);
		i++;
	}
	if (i != n)
		return (str11[i] - str22[i]);
	return (0);
}
