/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:42:38 by rbatson           #+#    #+#             */
/*   Updated: 2022/05/27 02:07:12 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map_empty(t_map *lst, char *map)
{
	int		fd;
	int		gnl;
	char	*line;
	int		len_line;

	line = NULL;
	lst->height = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0 || (read(fd, 0, 0) < 0))
		error_output("Not can read\n");
	while (1)
	{
		gnl = get_next_line(fd, &line);
		len_line = ft_strlen(line);
		check_map(lst, len_line, gnl);
		lst->width = len_line;
		lst->height++;
		free(line);
		if (gnl == 0)
			break ;
	}
	close(fd);
}

void	fill_map(t_map *lst, char *map)
{
	int		fd;
	int		s;
	int		gnl;
	char	*line;

	line = NULL;
	s = 0;
	fd = open(map, O_RDONLY);
	while (1)
	{
		gnl = get_next_line(fd, &line);
		lst->map[s] = ft_strdup(line);
		s++;
		free(line);
		if (gnl == 0)
			break ;
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	t_map	lst;

	if (argc != 2)
		error_output("Argc != 2");
	check_map_name(argv[1]);
	check_map_empty(&lst, argv[1]);
	lst.map = ft_calloc(lst.height + 1, sizeof(char *));
	fill_map(&lst, argv[1]);
	check_map_parametrs(&lst);
	if (lst.width > 39 || lst.height > 17)
		error_output("Went beyond the map\n");
	work_minilib(&lst);
	free(lst.map);
	return (1);
}
