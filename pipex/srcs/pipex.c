/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:07:44 by seungsle          #+#    #+#             */
/*   Updated: 2021/09/09 09:39:25 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	parent_process(char **argv, char **envp, int *fd_pipe)
{
	char	**cmd;
	char	*path;

	redirect_out(argv[4], fd_pipe);
	cmd = get_cmd(argv[3]);
	path = get_cmd_path(cmd[0], envp);
	if (execve(path, cmd, envp) == -1)
		error(cmd, path, "Error", 2);
	free(path);
	free_util(cmd);
	return (0);
}

static int	child_process(char **argv, char **envp, int *fd_pipe)
{
	char	**cmd;
	char	*path;

	redirect_in(argv[1], fd_pipe);
	cmd = get_cmd(argv[2]);
	path = get_cmd_path(cmd[0], envp);
	if (execve(path, cmd, envp) == -1)
		error(cmd, path, "Error", 2);
	free(path);
	free_util(cmd);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	pid;
	int	pipe_fd[2];
	int	status;

	if (argc == 5)
	{
		pipe(pipe_fd);
		pid = fork();
		if (pid == 0)
			child_process(argv, envp, pipe_fd);
		waitpid(pid, &status, 0);
		if (status != 0)
		{
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			error(NULL, NULL, "Child Process Error", 3);
		}
		parent_process(argv, envp, pipe_fd);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
	}
	else
		error(NULL, 0, "Bad argument", 1);
}
