/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:32:17 by rbatson           #+#    #+#             */
/*   Updated: 2021/10/26 16:31:12 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	dst_len;
	size_t	src_len;
	size_t	result;
	size_t	i;

	s = (char *)src;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(s);
	result = 0;
	i = 0;
	if (size > dst_len)
		result = src_len + dst_len;
	else
		result = src_len + size;
	while (s[i] && (dst_len + 1) < size)
	{
		dst[dst_len] = s[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = '\0';
	return (result);
}
