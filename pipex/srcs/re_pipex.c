/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:07:44 by seungsle          #+#    #+#             */
/*   Updated: 2021/09/06 16:18:28 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	redirect_in(char *argv, int *fd_pipe)
{
	int	fd_filein;

	fd_filein = open(argv, O_RDONLY);
	dup2(fd_filein, STDIN_FILENO);
	dup2(fd_pipe[1], STDOUT_FILENO);
	close(fd_pipe[0]);
	return (0);
}

int	redirect_out(char *argv, int *fd_pipe)
{
	int	fd_fileout;

	fd_fileout = open(argv, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	dup2(fd_fileout, STDOUT_FILENO);
	dup2(fd_pipe[0], STDIN_FILENO);
	close(fd_pipe[1]);
	return (0);
}

int	parent_process(char **argv, char **envp, int *fd_pipe)
{
	redirect_out(argv[4], fd_pipe);
}

int	child_process(char **argv, char **envp, int *fd_pipe)
{
	redirect_in(argv[1], fd_pipe);
}

int main(int argc, char **argv, char **envp)
{
	int	pid;
	int	pipe_fd[2];

	pipe(pipe_fd);
	pid = fork();
	if (pid == 0)
		child_process(argv, envp, pipe_fd);
	waitpid(pid, NULL, 0);
	parent_process(argv, envp, pipe_fd);
}
