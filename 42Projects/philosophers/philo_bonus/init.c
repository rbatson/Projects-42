/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:41:14 by rbatson           #+#    #+#             */
/*   Updated: 2022/07/01 23:37:25 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_semaphores(t_env *env)
{
	sem_unlink(FORK_SEM);
	sem_unlink(WRITE_SEM);
	sem_unlink(DEAD_SEM);
	sem_unlink(DEADW_SEM);
	env->forks_s = ft_sem_open(FORK_SEM, env->amount);
	env->write_s = ft_sem_open(WRITE_SEM, 1);
	env->died_s = ft_sem_open(DEAD_SEM, 0);
	env->died_write_s = ft_sem_open(DEADW_SEM, 1);
	if ((env->forks_s < 0) || (env->write_s < 0)
		|| (env->died_s < 0) || (env->died_write_s < 0))
		return (1);
	return (0);
}

static int	init_philos(t_env *env)
{
	int		i;
	char	semaphore[250];

	i = 0;
	while (i < env->amount)
	{
		env->philos[i].is_eating = 0;
		env->philos[i].id = i;
		env->philos[i].env = env;
		make_semaphore_name(PHILO_SEM, (char *)semaphore, i);
		sem_unlink(semaphore);
		env->philos[i].sem = ft_sem_open(semaphore, 1);
		if (env->philos[i].sem < 0)
			return (1);
		make_semaphore_name(PHILOEAT_SEM, (char *)semaphore, i);
		sem_unlink(semaphore);
		env->philos[i].eat_s = ft_sem_open(semaphore, 0);
		if (env->philos[i].eat_s < 0)
			return (1);
		i++;
	}
	return (0);
}

int	init(t_env *env, int argc, char const **argv)
{
	env->amount = ft_atoi(argv[1]);
	env->to_die = ft_atoi(argv[2]);
	env->to_eat = ft_atoi(argv[3]);
	env->to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		env->to_end_count = ft_atoi(argv[5]);
	else
		env->to_end_count = 0;
	env->forks_s = NULL;
	env->philos = (t_philo *)malloc(sizeof(*(env->philos)) * env->amount);
	if (!(env->philos))
		return (1);
	init_philos(env);
	return (init_semaphores(env));
}

int	clear_env(t_env *env)
{
	int		i;
	char	semaphore[255];

	sem_unlink(FORK_SEM);
	sem_unlink(WRITE_SEM);
	sem_unlink(DEAD_SEM);
	sem_unlink(DEADW_SEM);
	if (env->philos)
	{
		i = 0;
		while (i < env->amount)
		{
			make_semaphore_name(PHILO_SEM, (char *)semaphore, i);
			sem_unlink(semaphore);
			make_semaphore_name(PHILOEAT_SEM, (char *)semaphore, i++);
			sem_unlink(semaphore);
		}
		free(env->philos);
	}
	return (1);
}

int	exit_error(char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	return (1);
}
