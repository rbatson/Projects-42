/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:42:41 by rbatson           #+#    #+#             */
/*   Updated: 2022/05/27 02:07:14 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map_name(char *map_name)
{
	char	*map_extension;

	map_extension = ft_strrchr(map_name, '.');
	if (!map_extension)
		error_output("No point\n");
	if (ft_strcmp(map_extension, ".ber") != 0)
		error_output("No .ber extension\n");
}

void	check_map(t_map *lst, int len_line, int gnl)
{
	if (len_line == 0)
		error_output("File error\n");
	if (lst->height != 0 && len_line != lst->width)
		error_output("It is not rectangle\n");
	if (gnl == 0 && lst->height == 0)
		error_output("Only one line\n");
}

void	error_output(char *error)
{
	printf("%s", error);
	exit(1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strrchr(const char *s, int c)
{
	int	k;

	k = 0;
	while (s[k])
	{
		if (s[k] == (char)c)
			return ((char *)s + k);
		k++;
	}
	return (0);
}
