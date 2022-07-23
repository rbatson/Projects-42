/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:24:16 by rbatson           #+#    #+#             */
/*   Updated: 2021/10/12 02:21:39 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	char	*d;

	d = (char *)s;
	while (n > 0)
	{
		d[n - 1] = '\0';
		n--;
	}
	return (s);
}
