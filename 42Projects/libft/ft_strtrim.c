/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:44:17 by rbatson           #+#    #+#             */
/*   Updated: 2021/10/26 17:35:23 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_finding_char(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*result;
	size_t		i;
	size_t		k;
	size_t		len;

	i = 0;
	k = 0;
	len = ft_strlen(s1);
	if (!s1)
		return (0);
	while (s1[i] && ft_finding_char(s1[i], set))
		i++;
	while (len > i && ft_finding_char(s1[len - 1], set))
		len--;
	result = (char *)malloc(sizeof (*s1) * (len - i + 1));
	if (!result)
		return (0);
	while (i < len)
		result[k++] = s1[i++];
	result[k] = 0;
	return (result);
}
