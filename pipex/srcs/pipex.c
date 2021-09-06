/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:07:44 by seungsle          #+#    #+#             */
/*   Updated: 2021/09/06 18:05:06 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	parent_process(char **argv, char **envp, int *fd_pipe)
{
	char	**cmd;

	redirect_out(argv[4], fd_pipe);
	cmd = get_cmd(argv[3]);
	if (execve(get_cmd_path(cmd[0], envp), cmd, 0))
		error("Error", 2);
	return (0);
}

static int	child_process(char **argv, char **envp, int *fd_pipe)
{
	char	**cmd;

	redirect_in(argv[1], fd_pipe);
	cmd = get_cmd(argv[2]);
	if (execve(get_cmd_path(cmd[0], envp), cmd, 0) == -1)
		error("Error", 2);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	pid;
	int	pipe_fd[2];

	if (argc == 5)
	{
		pipe(pipe_fd);
		pid = fork();
		if (pid == 0)
			child_process(argv, envp, pipe_fd);
		waitpid(pid, NULL, 0);
		parent_process(argv, envp, pipe_fd);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}
	else
		error("Bad argument", 1);
}
