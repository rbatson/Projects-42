/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:58:25 by rbatson           #+#    #+#             */
/*   Updated: 2022/03/22 12:14:20 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countword(char const *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
		{
			count++;
			while ((*s != ' ' && *s != '\t') && *s != '\0')
				s++;
		}
		else
			s++;
	}
	return (count);
}

int	ft_wordmalloc(char const *s, char **mass)
{
	int	lenword;
	int	i;

	i = 0;
	while (*s)
	{
		lenword = 0;
		if (*s != ' ' && *s != '\t')
		{
			while ((*s != ' ' && *s != '\t') && *s != '\0')
			{
				s++;
				lenword++;
			}
			mass[i++] = ((char *)malloc(sizeof(char) * (lenword + 1)));
			if (!mass)
				return (i);
		}
		else
			s++;
	}
	return (0);
}

void	ft_rewriting(char const *s, char **mass)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
		{
			while ((*s != ' ' && *s != '\t') && *s != '\0')
				mass[i][j++] = *s++;
			mass[i++][j] = '\0';
		}
		j = 0;
		if (*s != '\0')
			s++;
	}
}

char	**ft_strsplit(char const *s, int word)
{
	char	**mass;
	int		res;

	if (!s)
		return (NULL);
	mass = (char **)malloc(sizeof(char *) * (word + 1));
	if (!mass)
		exit(1);
	mass[word] = NULL;
	res = ft_wordmalloc(s, mass);
	if (res == 0)
		ft_rewriting(s, mass);
	else
	{
		while (res != 0)
		{
			free(mass[res]);
			mass[res--] = NULL;
		}
		free(mass);
	}
	return ((char **)mass);
}
