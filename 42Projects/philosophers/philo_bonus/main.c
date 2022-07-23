/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:41:34 by rbatson           #+#    #+#             */
/*   Updated: 2022/07/01 23:37:27 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*monitor_count(void *env_v)
{
	t_env	*env;
	int		total;
	int		i;

	env = (t_env *)env_v;
	total = 0;
	while (total < env->to_end_count)
	{
		i = 0;
		while (i < env->amount)
			sem_wait(env->philos[i++].eat_s);
		total++;
	}
	display_message(&env->philos[0], TYPE_OVER);
	sem_post(env->died_s);
	return ((void *)0);
}

static void	*monitor_died(void *philo_v)
{
	t_philo		*philo;

	philo = (t_philo *)philo_v;
	while (1)
	{
		sem_wait(philo->sem);
		if (!philo->is_eating && get_time() > philo->limit)
		{
			display_message(philo, TYPE_DIED);
			sem_post(philo->sem);
			sem_post(philo->env->died_s);
			return ((void *)0);
		}
		sem_post(philo->sem);
		usleep(1000);
	}
	return ((void *)0);
}

static int	routine(t_philo *philo_v)
{
	t_philo		*philo;
	pthread_t	tid;

	philo = (t_philo *)philo_v;
	philo->last_eat = get_time();
	philo->limit = philo->last_eat + philo->env->to_die;
	if (pthread_create(&tid, NULL, &monitor_died, philo) != 0)
		return (1);
	pthread_detach(tid);
	while (1)
	{
		take_forks(philo);
		eat(philo);
		clean_forks(philo);
		display_message(philo, TYPE_THINK);
	}
	return (0);
}

static int	start_process(t_env *env)
{
	int			i;

	env->start = get_time();
	i = 0;
	while (i < env->amount)
	{
		env->philos[i].pid = fork();
		if (env->philos[i].pid < 0)
			return (1);
		else if (env->philos[i].pid == 0)
		{
			routine(&env->philos[i]);
			exit(0);
		}
		usleep(100);
		i++;
	}
	return (0);
}

int	main(int argc, char const **argv)
{
	int			i;
	t_env		env;
	pthread_t	tid;

	if (argc < 5 || argc > 6)
		return (exit_error("error: bad arguments\n"));
	if (init(&env, argc, argv))
		return (clear_env(&env) && exit_error("init error\n"));
	if (env.to_end_count > 0)
	{
		if (pthread_create(&tid, NULL, &monitor_count, (void *)&env) != 0)
			return (1);
		pthread_detach(tid);
	}
	if (start_process(&env))
		return (clear_env(&env) && exit_error("start process error\n"));
	sem_wait(env.died_s);
	i = 0;
	while (i < env.amount)
		kill(env.philos[i++].pid, SIGKILL);
	clear_env(&env);
	return (0);
}
