/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:41:42 by rbatson           #+#    #+#             */
/*   Updated: 2022/07/01 23:37:35 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

# define FORK_SEM		"ForkSem"
# define WRITE_SEM		"WriteSem"
# define DEAD_SEM		"DiedSem"
# define DEADW_SEM		"DiedWriteSem"
# define PHILO_SEM		"PhiloSem"
# define PHILOEAT_SEM	"PhiloEatSem"

# define TYPE_EAT 	0
# define TYPE_SLEEP 1
# define TYPE_FORK 	2
# define TYPE_THINK	3
# define TYPE_DIED 	4
# define TYPE_OVER 	5

struct	s_env;

typedef struct s_philo
{
	pid_t				pid;
	int					id;
	int					is_eating;
	unsigned long long	limit;
	unsigned long long	last_eat;
	int					eat_count;
	struct s_env		*env;
	sem_t				*sem;
	sem_t				*eat_s;
}						t_philo;

typedef struct s_env
{
	int					amount;
	unsigned long long	to_die;
	unsigned long long	to_eat;
	unsigned long long	to_sleep;
	int					to_end_count;
	unsigned long long	start;
	t_philo				*philos;
	sem_t				*forks_s;
	sem_t				*write_s;
	sem_t				*died_s;
	sem_t				*died_write_s;
}						t_env;

size_t				ft_strlen(char const *str);
int					ft_atoi(char const *str);
void				ft_putnbr_fd(unsigned long long n, int fd);
size_t				ft_strcpy(char *dst, const char *src);
unsigned long long	get_time(void);
int					clear_env(t_env *env);
int					exit_error(char const *str);
int					init(t_env *env, int argc, char const **argv);
sem_t				*ft_sem_open(char const *name, int value);
char				*make_semaphore_name(char const *base,
						char *buffer, int position);
void				take_forks(t_philo *philo);
void				clean_forks(t_philo *philo);
void				eat(t_philo *philo);
void				display_message(t_philo *philo, int type);

#endif