/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:08:38 by seungsle          #+#    #+#             */
/*   Updated: 2021/09/04 15:22:37 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int redirect_in(char **argv, int *fd_pipe)
{
	int	file_in;

	file_in = open(argv[1], O_RDONLY);
	dup2(fd_pipe[0], STDIN_FILENO);
	dup2(file_in, STDOUT_FILENO);
	close(fd_pipe[1]);
	return (0);
}

int	redirect_out(char **argv, int *fd_pipe)
{
	int file_out;

	file_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(fd_pipe[1], STDOUT)
}

int main(int argc, char **argv, char **envp)
{
	int	fd_pipe[2]; // pipe array
	int	pid;

	pipe(fd_pipe);
	pid = fork();
	if (pid == 0)
	{
		printf("child process\n");
		redirect_in(argv, fd_pipe);
	}
	else
	{
		waitpid(pid, NULL, 0);
		printf("parent process\n");
		redirect_out(argv, fd_pipe);
	}
}
