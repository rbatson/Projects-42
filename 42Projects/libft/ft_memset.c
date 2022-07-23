/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:40:05 by rbatson           #+#    #+#             */
/*   Updated: 2021/10/26 16:21:34 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*strr;
	unsigned char	cc;

	strr = (unsigned char *)str;
	cc = (unsigned char)c;
	while (len > 0)
	{
		len --;
		strr[len] = cc;
	}
	return (str);
}
