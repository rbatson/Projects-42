/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 02:14:27 by rbatson           #+#    #+#             */
/*   Updated: 2021/10/26 16:18:44 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*srcc;
	char	*dstt;
	size_t	i;

	if (src == dst)
		return (dst);
	srcc = (char *)src;
	dstt = (char *)dst;
	if (dst > src)
	{
		i = len;
		while (i-- > 0)
			dstt[i] = srcc[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dstt[i] = srcc[i];
			i++;
		}
	}
	return (dst);
}
