/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:03:52 by rbatson           #+#    #+#             */
/*   Updated: 2021/10/26 16:38:39 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_copy(const char *string, const char *secondstring, char *result)
{
	size_t	a;
	size_t	c;

	a = 0;
	c = 0;
	while (string[a])
	{
		result[c] = string[a];
		a++;
		c++;
	}
	a = 0;
	while (secondstring[a])
	{
		result[c] = secondstring[a];
		a++;
		c++;
	}
	result[c] = '\0';
	return (*result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (s1 == 0 || s2 == 0)
		return (0);
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (res == 0)
		return (0);
	ft_copy(s1, s2, res);
	return (res);
}
