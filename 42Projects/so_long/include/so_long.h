/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 21:41:44 by rbatson           #+#    #+#             */
/*   Updated: 2022/05/31 09:51:45 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stddef.h>
# include <time.h>
# include <mlx.h>

typedef struct st_map
{
	char	**map;
	int		width;
	int		height;
	int		sum_player;
	int		sum_barrier;
	int		sum_enemy;
	int		sum_goal;
	int		sum_exit;
}	t_map;

typedef struct s_vars
{
	int		frame;
	int		time;
	int		height;
	int		count;
	char	**var_map;
	void	*mlx;
	void	*win;
	void	*img;
	void	*img_cube;
	void	*img_jhonny;
	void	*img_amber_normal;
	void	*img_amber_broken;
	void	*img_collectible;
	void	*img_enemy1;
	void	*img_enemy2;
	void	*img_barrier;
	void	*img_space;
	int		img_width;
	int		img_height;
	int		person_x;
	int		person_y;
	int		exit_x;
	int		exit_y;
	int		sum_goals;
}	t_vars;

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dst, const char *src);
int		get_next_line(int fd, char **line);

void	error_output(char *error);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strrchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
int		animation(t_vars *vars);

void	check_map_name(char *map_name);
void	check_other_wall(t_map *lst);
void	check_all_other(t_map *lst, int i, int k);
void	check_first_and_last_line(t_map *lst, int i);
void	check_map_empty(t_map *lst, char *map);
void	check_map(t_map *lst, int len_line, int gnl);
void	check_map_parametrs(t_map *lst);
void	work_minilib(t_map *lst);
void	move_person(t_vars *vars, int keycode);
void	image_position(t_map *lst, t_vars *vars);
void	move(t_vars *vars, int move);
void	move_jhonny(t_vars *vars, char s, int x, int y);
void	image_print(char a, t_vars *vars, int i, int k);

#endif