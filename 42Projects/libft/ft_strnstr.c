/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:38:28 by rbatson           #+#    #+#             */
/*   Updated: 2021/10/26 17:34:17 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	unsigned int	i;
	unsigned int	k;

	i = 0;
	if (!*str2)
		return ((char *)str1);
	while (str1[i] && i < len)
	{
		if (str1[i] == str2[0])
		{
			k = 1;
			while (str2[k] && str1[i + k] == str2[k] && (i + k) < len)
				k++;
			if (str2[k] == '\0')
				return ((char *)&str1[i]);
		}
		i++;
	}
	return (0);
}
