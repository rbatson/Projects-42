/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbatson <rbatson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:14:30 by rbatson           #+#    #+#             */
/*   Updated: 2022/03/26 20:40:45 by rbatson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	openfile(char *file, int mode)
{
	if (mode == 0)
	{
		if (access(file, F_OK))
		{
			write(2, "File not found\n", 15);
			return (0);
		}
		return (open(file, O_RDONLY));
	}
	else
		return (open(file, O_CREAT | O_WRONLY | O_TRUNC));
}

char	*full_command_path(char *cmd, char **env)
{
	int		i;
	char	*path;
	char	*dir;
	char	*full;

	i = 0;
	while (env[i] && ncompare(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (cmd);
	path = env[i] + 5;
	while (path && len_ch(path, ':') > -1)
	{
		dir = str_ndup(path, len_ch(path, ':'));
		full = make_command(dir, cmd);
		free(dir);
		if (access(full, F_OK) == 0)
			return (full);
		free(full);
		path += len_ch(path, ':') + 1;
	}
	return (cmd);
}

void	second_command_processing(char *command, char **env)
{
	char	**args;
	char	*path;

	args = str_split(command, ' ');
	if (len_ch(args[0], '/') > -1)
		path = args[0];
	else
		path = full_command_path(args[0], env);
	execve(path, args, env);
	write(2, "Сommand not found\n", 19);
	exit(127);
}

void	first_command_processing(char *command, char **env, int infile_fd)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], 0);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		if (infile_fd == 0)
			exit(1);
		else
			second_command_processing(command, env);
	}
}

int	main(int ac, char **av, char **env)
{
	int	infile_fd;
	int	outfile_fd;

	if (ac == 5)
	{
		infile_fd = openfile(av[1], 0);
		outfile_fd = openfile(av[4], 1);
		dup2(infile_fd, 0);
		dup2(outfile_fd, 1);
		first_command_processing(av[2], env, infile_fd);
		second_command_processing(av[3], env);
	}
	else
		write(2, "Нужно 4 аргумента\n", 29);
	return (1);
}
